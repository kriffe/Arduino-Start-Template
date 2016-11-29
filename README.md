# Arduino Start Template

Lets get started with arduino.

Simple setup for the following components

1. Move a servo
2. Read an digital input (button)
3. Read an analog input (sensor)
4. Digital output
5. Debugging
6. Run a slow timer

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

  delay(200);)
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
```C
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
```

Attach

Move

## Analog Read

## Buttons

Analog read





## Controll a Servo

