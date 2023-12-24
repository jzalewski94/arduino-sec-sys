/*Here I am using the keypad libary to help me easily make a functional keypad.*/
#include <Keypad.h>




/*I have a bunch of consts here, things that aren't changing such as:
 * Armed/Disarmed LED lights on digital pin 10 and 11.
 * Door sensor on digital pin 13.
 * 
 * The row and column numbers because my physical keypad consists of a 4x4 Matrix.
 * 
 * Hard set usrpassword String. I am not currently using this, but will be worked on in the future.
 */
const int armedLED = 10;
const int disarmedLED = 11;
const int doorSensor = 13;
const int rowNum = 4;
const int colNum = 4;
const String usrPassword = "2194";







/*
 * Some booleans here, such as:
 * Is the alarm active/armed?
 * Did the password attempt succeed?
 * Has the alarm been triggered? (This one is being used the most)
 */
bool alarmActive = true;
bool passwordAttemptSucceed = false;

bool alarmTriggered = false;


/*
 * Int to hold the on/off value of my door sensor.
 */
int doorSensorVal = 0;



/*
 * I grabbed this code from the internet, so it was not written by me. 
 * You're making an array called keys that consists of 2 different axis (Row...Col...)
 * This is the physical layout of the keypad.
 */
char keys [rowNum][colNum] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

/*
 * Here we are making variables of the byte type that will let us know where to place our wires into what pins. 
 * My keypad did not come with any documentation so this was trial and error for me.
 */
byte pin_rows[rowNum] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[colNum] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad


/*
 * I do not know how this function works, but this is essentially creating our keypad using the data above. 
 */
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, rowNum, colNum );

 
 
 /*
  * WIP Function. This and AlarmTriggered are WIP.
  */
 void PasswordAuth(){
    bool passwordCorr = false;
    int keyPresses = 0;
    char usrAttempt[3];

 
 
    while (passwordCorr == false && alarmTriggered == true){
      char keyPressed = keypad.getKey();

      switch(keypad.getState()){        
        case PRESSED:
        if( keyPressed == '2'){
          usrAttempt[0] = keyPressed;
          Serial.println(usrAttempt);
        }else if ( keyPressed == '1'){
          usrAttempt[1] = keyPressed;
          Serial.println(usrAttempt);
        }else if( keyPressed == '9'){
          usrAttempt[2] = keyPressed;
          Serial.println(usrAttempt);
        }else if( keyPressed == '4'){
          usrAttempt[3] = keyPressed;
          Serial.println(usrAttempt);

    }
  }
      if(usrAttempt[0] == '2' && usrAttempt[1] == '1' && usrAttempt[2] == '9' && usrAttempt[3] == '4'){
        
        Serial.println(usrAttempt);
        for(int i = 0; i < 4; i++){
          usrAttempt[i] = 0;
        }
        Serial.println(usrAttempt);
        passwordCorr = true;
         alarmTriggered = false;
        Serial.println(alarmTriggered);
        Serial.println(passwordCorr);
      }
      
}


 return;
}




/*
 * In my setup function, I open the serial monitor so I can use it for debugging.
 * I'm setting my LEDs to be an OUTPUT and the door sensor to be an INPUT.
 */
void setup() {
 Serial.begin(9600);

 pinMode(armedLED, OUTPUT);
 pinMode(disarmedLED, OUTPUT);
 pinMode(doorSensor, INPUT);

}



/*
 * In my loop function, I'm setting the doorSensorVal to read what ever is on digital pin 13(doorSensor).
 * 
 */
void loop() {
  doorSensorVal = digitalRead(doorSensor);
  
  /*
   * This is my first if statement in the program. It's checking to see if the door sensor value has changed.
   * If it switches to an ON state (1), it will set the alarm triggered value to TRUE and call the AlarmTriggered method.
   */
   if(doorSensorVal < 1){
    alarmTriggered = false;
  } else if(doorSensorVal == 1){
    alarmTriggered = true;
    AlarmTriggered();
    
  }



   /*
    * This IF statement is essentially here to control LEDs and give the user feedback. 
    * The first IF statement is checking to see if the alarm is active, not triggered, and the sensors aren't going off.
    * If all of this is met, it will set the armed LED to ON( HIGH) and print an message stating the alarmed is armed.
    *
    *The second IF statement is checking to see if the alarm is not active, has been reset and if the door sensor value isn't
    *being triggered (0). If all of these are met, it will ask if you want to re-arm the alarm. This IF statement should only be
    *called once the AlarmTriggered method has been satisified. 
    */
  if(alarmActive == true && alarmTriggered == false && doorSensorVal < 1){
    digitalWrite(armedLED, HIGH);
    Serial.println("Alarmed Armed.");
  } else if(alarmActive == false && alarmTriggered == false && doorSensorVal < 1){
    Serial.println("Do you wish to re arm the alarm?");
  }


  

}



/*
 * The AlarmTriggered method should only be called if the doorSensorVal goes off (ON, 1). The user will have to make sure
 * the door is securely closed or off the sensor before trying to reset the alarm. 
 */
void AlarmTriggered(){
    
      
      /*
       * When this method is called, it sets the alarm to be inactive. In the future, I will have to make the re-arming function. 
       * 
       * It is also setting the LEDs to their correct setting. (Red = HIGH for alarm on/inactive. Green = LOW)
       * An 'Alarm Triggered!" message also goes off.
       */
      alarmActive = false;
      digitalWrite(armedLED, LOW);
      digitalWrite(disarmedLED, HIGH);
      Serial.println("Alarmed Triggered!");

      
    /*
     * Here is a while loop that continues to run while the alarm variable is true. This is an WIP.
     */
     while(alarmTriggered == true){
        char passwordAttempt[4];
        int keyPressed = 4;
        int i = 0;
        int passwordCountdown = 10;
        Serial.println("Please enter the disarm password.");
        Serial.println("You have 10 seconds to enter the password, followed by #.");
        Serial.println(doorSensorVal);
        PasswordAuth();
       

          }

        }
        




 
  
