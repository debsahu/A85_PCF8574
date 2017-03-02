#include <A85_PCF8574.h>
// SDA - P0 - 0 // CLK - P2 - 2

#define PCF8574_ADDRESS (0x20)

A85_PCF8574 myPCF8574;
int counter = 0;
int dir = 1;

void timerCB() {
	//myPCF8574.setByte(~((uint8_t)1<<counter));
	myPCF8574.setBit(counter, dir > 0);
	counter += dir;
	if (counter == 8) {
		counter = 7;
		dir = -1;
	} else if (counter == -1) {
		counter = 0;
		dir = 1;
	}
}

void setup()
{
	myPCF8574.begin(PCF8574_ADDRESS);
}

// The loop function is called in an endless loop
void loop()
{
  timerCB();
  delay(500);
}