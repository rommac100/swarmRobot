#include <Arduino.h>
#include "pins.h"
#include "StepperMotor.h"

StepperMotor motorLeft(5,4,0,2);
StepperMotor motorRight(14,12,13,15);

const static int stepsPerInches = 410;

long ultraSonicGetVal()
{
   long duration, inches;

   //turning on Sensor
   pinMode(ultra12PinOut, OUTPUT);
   digitalWrite(ultra12PinOut, LOW);
   delayMicroseconds(2);
   digitalWrite(ultra12PinOut, HIGH);
   delayMicroseconds(10);
   digitalWrite(ultra12PinOut, LOW);

   pinMode(ultra1PinIN, INPUT);
   duration = pulseIn(ultra1PinIN, HIGH);

   inches = duration/74/2;

   return inches;
}

void turn(int angle)
{
if (angle > 0)
{
  int steps = 0;
  while (steps < angle/3*stepsPerInches)
  {
    motorLeft.step(-10);
    motorRight.step(-10);
    steps += 10;
  }
}
  else if (angle < 0)
  {
    int steps = 0;
    while (steps < angle/3*stepsPerInches)
    {
      motorLeft.step(10);
      motorRight.step(10);
      steps+= 10;
    }
  }
}


void moveDir(double inches)
{
  if (inches > 0)	
  {
       int steps = 0;
       while (steps < (int)inches*stepsPerInches)
       {
       motorLeft.step(-10);
       motorRight.step(10);
       steps += 10;
     }
  }
  else if (inches < 0)
  {
    int steps = 0;
    while (steps < (int)inches*stepsPerInches)
    {
       motorLeft.step(10);
       motorRight.step(-10);
    }
  }

}

void setup(){
  Serial.begin(9600);
  motorLeft.setStepDuration(1);
  motorRight.setStepDuration(1);
}

void loop(){
//moveDir(5);
turn(90);
delay(10000);
/*
while (ultraSonicGetVal() > 22)
  {
    motorLeft.step(-10);
    motorRight.step(10);
    /*
  int stepCount = 0;
  while (stepCount<4096)
  {
    motorLeft.step(10);
    motorRight.step(10);
    stepCount+= 10;
  }
  delay(1000);
  //}
  */
//}

  //delay(5000);

}
