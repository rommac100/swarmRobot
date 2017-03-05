#include <Stepper.h>
Stepper leftStepper(4096, lStepP0, lStepP1, lStepP2, lStepP3);
Stepper rightStepper(4096, rStepP0, rStepP1, rStepP2, rStepP3);
#define  TIMEOUT     4000    //Turns off steppers after 4 sec of inactivity.


double ultraSonicGetVal()
{
   long duration, inches;

   //turning on Sensor
   pinMode(ultra1PinOut, OUTPUT);
   digitalWrite(ultra1PinOut, LOW);
   delayMicroseconds(2);
   digitalWrite(ultra1PinOut, HIGH);
   delayMicroseconds(10);
   digitalWrite(ultra1PinOut, LOW);

   pinMode(ultra1PinIN, INPUT);

   duration = pulseIn(ultra1PinIN, HIGH);

   inches = duration/74/2;

   return inches;
}

void CheckTimeout(){
  if((millis() - timeStamp) > TIMEOUT){   //Turn Off StepperX coils.
    digitalWrite(lStepP0, LOW);
    digitalWrite(lStepP1, LOW);
    digitalWrite(lStepP2, LOW);
    digitalWrite(lStepP3, LOW);
    digitalWrite(rStepP0, LOW);
    digitalWrite(rStepP1, LOW);
    digitalWrite(rStepP2, LOW);
    digitalWrite(rStepP3, LOW);
  }
}//As per ardunaut on arduining.com https://arduining.com/2015/05/30/arduino-and-two-stepper-motors/
double[] moveForward(double runDist, double netAngle)
{
  yPos = runDist*Math.cos(netAngle);
  xPos = runDist*Math.sin(netAngle);
  double stepDist = runDist/2;
  int stepCount = 0;
  while(stepCount < (int)stepDist)
  {
    leftStepper.step(1);
    rightStepper.step(1);
  }
  timeStamp = millis()
  return [xPos,yPos];
}
double moveTurn(double angleTurn, double netAngle)
{
  postNetAngle = netAngle+angleTurn;
  double runDist = 2.25*angleTurn;
  double stepDist = runDist/2;
  int stepCount = 0;
  while(stepCount<(int)stepDist)
  {
    leftStepper.step(-1);
    rightStepper.step(1);
  }
  timeStamp = millis()
  return postNetAngle;
}
