#include "Tlc5940.h"
#include "arduino.h"
int pins[9]={7,6,8,5,16,4,14,2,15};
uint8_t outerborder[32]={0,1,2,3,4,5,6,7,8,17,26,35,44,53,62,71,80,79,78,77,76,75,74,73,72,63,54,45,36,27,18,9};
int8_t led[729];
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(12, INPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  Tlc.init();
  Serial.begin(115200);
}
void loop() {
  Blocks(10,10);
  RandomFill(2916,1);
  Sine(1000, 0);
  Display(300);
  Wave(1000,21);
  CornerShrink();
  
  CubicSpiral(1000);
Spiral(500);


Sine(800, 2);
Extendo(10,50);

RandomDim(2000,2);
//digitalWrite(4, LOW);
//Test(10000);
Rain(2000,30);
//SimpleTest(100);
RandomUpDown(162, 0, 0);
RandomUpDown(200, 0, 1);

//Blocks(10,10);//Not done mapping has a lot of errors
//Pyramid();

//CubeOutline(2,2,2,4,300);

}

int CubeXYZ(int xcor, int ycor, float zcor)
{
  return ((zcor * 81) + (ycor * 9) + xcor);
}

void swapInt(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
