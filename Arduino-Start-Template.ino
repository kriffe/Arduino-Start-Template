//Servo
//Relay
//Diod
//Sensor in
//Time tracker
//Serial debug  


//Simple timer library for running tasks
//#include <SimpleTimer.h>
//SimpleTimer timer;

#include <Servo.h>
Servo myservo;  // create servo object to control a servo



//Pin assignment
int ledPin = 13;
int servoPin = 9;
int buttonPin = 1;
int sensorPin = 2;
int relayPin = 5;


//Global variables
int servoPosition = 0;  //0 - 180 degrees


//Simple debug function for sending message over serial
void sendDebugVariable(String title,int value){
  Serial.print(title);
  Serial.print(" : ");
  Serial.println(value);
}

//Example timer function for running slower than main loop
void timerFunction(){
   
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


  //Start an extra timer loop for slow functions
  //timer.setInterval(2000, timerFunction);
  
}


// put your main code in the loop ----------------------------------------------------------------------------
void loop() { 
  //timer.run();
  
  
  //Read button state and trigger action (simple setup)
  int buttonPinValue = digitalRead(buttonPin);
  if (buttonPinValue == HIGH){
    
      servoPosition = 180;
      
      
  }
  else{
    
      servoPosition = 0;
      
  }



  //Set servos position
  myservo.write(servoPosition);
  
  
  //Debug some every loop
  sendDebugVariable("Position debug",servoPosition);

  //Some loop delay for easier debugging
  delay(200);
}







