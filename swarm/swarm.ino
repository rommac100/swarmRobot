#include <Stepper.h>
int defaultStepsPerMil = 4096;
Stepper leftStepper(4096, 5, 6, 7, 8);
Stepper rightStepper(4096, 0, 1, 2, 3);
//    #define  TIMEOUT     1000    //Turns off after 1 sec of inactivity.
//    void CheckTimeout(){
//      if((millis() - stampX) > TIMEOUT){   //Turn Off StepperX coils.
//        digitalWrite(COIL_1X, LOW);
//        digitalWrite(COIL_2X, LOW);
//        digitalWrite(COIL_3X, LOW);
//        digitalWrite(COIL_4X, LOW);
//      }
//      if((millis() - stampY) > TIMEOUT){   //Turn Off StepperY coils.
//        digitalWrite(COIL_1Y, LOW);
//        digitalWrite(COIL_2Y, LOW);
//        digitalWrite(COIL_3Y, LOW);
//        digitalWrite(COIL_4Y, LOW);
//      }
//    }//As per ardunaut on arduining.com https://arduining.com/2015/05/30/arduino-and-two-stepper-motors/
double[] moveForward(double runDist, double netAngle)
{
  yPos = runDist*Math.cos(netAngle);
  xPos = runDist*Math.sin(netAngle);
  double stepDist = runDist/2;
  int stepCount = 0;
  while(stepCount < stepDist)
  {
    leftStepper.step(1);
    rightStepper.step(1);
  }
  return [xPos,yPos];
}
double moveTurn(double angleTurn, double netAngle)
{
  postNetAngle = netAngle+angleTurn;
  double runDist = 2.25*angleTurn;
  double stepDist = runDist/2;
  //run rightStepper at convRunDist;
  //run left Stepper at -convRunDist;
  return postNetAngle;
}

void calibration()
{
  double[] new = moveForward(1,0);

}

void setup()
{

}

void loop()
{

}
