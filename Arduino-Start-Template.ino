//Servo
//Relay
//Diod
//Sensor in
//Time tracker
//Serial debug  


#include <Servo.h>
Servo myservo;  // create servo object to control a servo



//Pin assignment
int ledPin = 13;
int servoPin = 9;
int buttonPin = A0;
int sensorPin = A1;
int relayPin = 8;


//Global variables
bool lightIsOn = false;
long timeStamp = 0;     //Timestamp for slow actions


//Simple debug function for sending message over serial
void sendDebugVariable(String title,int value){
  Serial.print(title);
  Serial.print(" : ");
  Serial.println(value);
}




// put your setup code in the setup section  --------------------------------------------------------------
void setup() {  
  

  //Initiate serial communications (USB)
  Serial.begin(9600);

  //Define pin typess
  pinMode(buttonPin,INPUT);
  pinMode(sensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(relayPin,OUTPUT);

  //Define servo pin through library
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

}


// put your main code in the loop ----------------------------------------------------------------------------
void loop() { 
  
  //Read inputs
  int buttonPinValue = analogRead(buttonPin);
  int sensor = analogRead(sensorPin);
  

  //Do seom logic on button press
  if (buttonPinValue > 900){  //1024 maxh  
      digitalWrite(relayPin,HIGH);
      myservo.write(120);
      
  }
  else{
      digitalWrite(relayPin,LOW);
      myservo.write(60);
      
  }


  //Simple slightly inaccurate timer for stuff
  if (millis() - timeStamp >= 2000){

    
    if (lightIsOn){
      digitalWrite(ledPin,LOW);
      lightIsOn = false;
    }
    else{
      digitalWrite(ledPin,HIGH);
      lightIsOn = true;
    }
    timeStamp = millis();
  }



  //Debug some every loop
  sendDebugVariable("Button",buttonPinValue);
  sendDebugVariable("Sensor input",sensor);
  //sendDebugVariable("Timer",millis()-timeStamp);
  
  
  
  delay(200);
}







