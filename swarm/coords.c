//Coordinates file
#ifndef COORDS_H
#define COORDS_H
int *xCoord = null;
int *yCoord = null;


int[] getCurrentPos();
void setCurrentPosOrigin(int currentPosX, int currentPosY);
void storeValuesEEPROM(int *coordX, int *coordY);

#endif
#include <EEPROM.h>

void storeValuesEEPROM(int *coordX, int *coordY)
{
  //clears EEPROM
  for (int i = 0 ; i < EEPROM.length(); i++)
  {
    EEPROM.write(i,0);
  }
//writes the decimal number that corespondes to X.
  EEPROM.write(0,88);
  int i = 0;
  int j = 1;
  //writes the xCoord pointer/array to EEPROM
  while (xCoord[i] != null)
  {
    EEPROM.write(j,xCoord[i])
    j++;
    i++;
  }
  i = 0;
  j += 1;
  //writes the decimal number that corespondes to X.
  EEPROM.write(j,88);
  j += 1;
  //writes the decimal number that corespondes to Y.
  EEPROM.write(j,89);
  j +=1;
  //writes the yCoord pointer/array to EEPROM
  while (yCoord[i] != null)
  {
    EEPROM.write(j)
  }
  j += 1;
    //writes the decimal number that corespondes to Y.
  EEPROM.write(j,89);
free(xCoord);
free(yCoord);
}


int[] getCurrentPos(int currentPosX, int currentPosY)
{
   int x = 0;
   int y = 0;
   bool foundX = false;
   bool foundY = false;

   //Does a liner search for now.
   while (!foundX)
   {
     if (xCoord[x] == currentPosX)
     {
       foundX = true;
     }
     x++;
   }
   while (!foundY)
   {
     if (yCoord[y] == currentPosY)
     {
       foundY = true;
     }
     y++;
   }
   int[2] currentCoord;
   currentCoord[0] = x;
   currentCoord[1] = y;
   return currentCoord;
}

void setCurrentPosOrigin(int currentPosX, int currentPosY)
{
  xCoord = malloc(sizeof(int)*10);
  yCoord = malloc(sizeof(int)*10);
  xCoord[0] = currentPosX;
  yCoord[0] = currentPosY;
}
