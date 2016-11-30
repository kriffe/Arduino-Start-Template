# Arduino Start Template

Lets get started with arduino.

Simple setup for the following components

1. Move a servo
2. Read an input (button/sensor)
3. Digital output (LED/Relay)
4. Debugging
5. Run a slow timer

## Overview

Setup
```
void setup(){
//Define all sensors
}
```

Fast loop (200 ms delay)
```
void loop(){

  //Do some stuff

  delay(200);
}

```

Simple slow loop (inside void loop(){})
```

if (millis() - timeStamp >= 2000){
  //Do some stuff
  timeStamp = millis();
}
```


## Servos

A servo can be controlled with the help of the [Arduinos servo library](https://www.arduino.cc/en/Reference/Servo).

Include and define
```
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
```

Attach servo (in setup)
```
myservo.attach(servoPin);
```

Move servo (0 - 180 degrees)
```
myservo.write(123);
```

## Analog Read

Reading of voltage input can be done with analogRead()/digtalRead()

Define in setup()
```
pinMode(sensorPin,INPUT);
```

Read analog value of sensor in loop()
```
int sensor = analogRead(sensorPin);   =>  0 - 1024
```




## Digital output
Switch output voltage between 0 and 5 V on pins.

Define in setup()
```
pinMode(relayPin,OUTPUT);
```

Set inside loop()
```
digitalWrite(relayPin,HIGH);
```


## Debugging
Use the comport and IDE console to debug your Arduino

Define helpfunction for messages
```
void sendDebugVariable(String title,int value){
  Serial.print(title);
  Serial.print(" : ");
  Serial.println(value);
}
```

Send debug command
```
sendDebugVariable("Button",buttonPinValue);
```



