#include <Keypad.h>;


const int armedLED = 10;
const int disarmedLED = 11;
const int doorSensor = 13;
const int rowNum = 4;
const int colNum = 4;
const String usrPassword = "1618";

bool alarmActive = true;
bool alarmInactive = false;
bool passwordAttemptSucceed = false;

bool alarmTriggered = false;

int doorSensorVal = 0;


char keys [rowNum][colNum] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte pin_rows[rowNum] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[colNum] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, rowNum, colNum );

 bool PasswordAuth(){
    bool passwordCorr = false;
    char keyPresses[4];

    while (passwordCorr = false){
      char keyPressed = keypad.getKey();
    }
    
  }

void setup() {
 Serial.begin(9600);

 pinMode(armedLED, OUTPUT);
 pinMode(disarmedLED, OUTPUT);
 pinMode(doorSensor, INPUT);

 

}

void loop() {
  doorSensorVal = digitalRead(doorSensor);
  
  
  if(alarmActive == true && alarmTriggered == false && doorSensorVal < 1){
    digitalWrite(armedLED, HIGH);
    Serial.println("Alarmed Armed.");
  } 
  
  else if(doorSensorVal >= 1){
    AlarmTriggered();
    
  }
 
 
}


  void AlarmTriggered(){
    
      alarmTriggered = true;
      alarmActive = false;
      digitalWrite(armedLED, LOW);
      digitalWrite(disarmedLED, HIGH);
      Serial.println("Alarmed Triggered!");
      
      
      
      
      while(alarmTriggered == true && alarmActive == false && PasswordAuth){
        char passwordAttempt[4];
        int keyPressed = 4;
        int i = 0;
        int passwordCountdown = 10;
        Serial.println("Please enter the arming password.");
        Serial.println("You have 10 seconds to enter the password, followed by #.");
        PasswordAuth();

        
          /*if(key != '#'){
            Serial.println(key);
            passwordAttempt[keyPressed] = key;
            keyPressed++;
          
          }*/
          
          }

          



          
        }
        
  char KeyPadFunc(){
    char key = keypad.getKey();
    if(key){
      Serial.println(key);
      
    }
  }



 
  
