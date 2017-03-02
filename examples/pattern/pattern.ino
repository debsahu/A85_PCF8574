#include <A85_PCF8574.h>
// SDA - P0 - 0 // CLK - P2 - 2

#define PCF8574_ADDRESS (0x20)

A85_PCF8574 myPCF8574;
int counter = 0;
int dir = 1;

void pattern1(){
  myPCF8574.setBit(0,0); delay(1000);
  myPCF8574.setBit(1,0); delay(1000);
  myPCF8574.setBit(2,0); delay(1000);
  myPCF8574.setBit(3,0); delay(1000);
  myPCF8574.setBit(4,0); delay(1000);
  myPCF8574.setBit(5,0); delay(1000);
  myPCF8574.setBit(6,0); delay(1000);
  myPCF8574.setBit(7,0); delay(1000);
  myPCF8574.setBit(0,1); delay(1000);
  myPCF8574.setBit(1,1); delay(1000);
  myPCF8574.setBit(2,1); delay(1000);
  myPCF8574.setBit(3,1); delay(1000);
  myPCF8574.setBit(4,1); delay(1000);
  myPCF8574.setBit(5,1); delay(1000);
  myPCF8574.setBit(6,1); delay(1000);
  myPCF8574.setBit(7,1); delay(1000);
}

void pattern2(){
  myPCF8574.setByte(B11110000);
  delay(1000);
  myPCF8574.setByte(B00001111);
  delay(1000);
}

void pattern3(){
  myPCF8574.setByte(B10101010);
  delay(1000);
  myPCF8574.setByte(B01010101);
  delay(1000);
}

void pattern4(){
  allon();
  delay(1000);
  alloff();
}

void alloff(){
  myPCF8574.setByte(B00000000);
}

void allon(){
  myPCF8574.setByte(B11111111);
}

void setup()
{
  myPCF8574.begin(PCF8574_ADDRESS);
}

// The loop function is called in an endless loop
void loop()
{
  //pattern1();
  //pattern2();
  pattern3();
  //pattern4();
}