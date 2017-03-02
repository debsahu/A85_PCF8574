#include <TinyWireM.h>
#include "A85_PCF8574.h"

/**
 * Constructor for the class
 */
A85_PCF8574::A85_PCF8574() {
	m_address = 0;
} // End of constructor

/**
 * Set the address and pins to be used for SDA and CLK in the Two Wire (I2C) protocol.
 */
void A85_PCF8574::begin(uint8_t address) {
	m_address = address; // Attiny85: SDA - P0 (0) & CLK - P2 (2)
	TinyWireM.begin();   // Can't change I2C pins
} // End of setPins

/**
 * Set the bit (range 0-7) of the GPIOs to the supplied value.
 */
void A85_PCF8574::setBit(uint8_t bit, bool value) {
	// Check that the bit is in range.  Must be 0-7.
	if (bit < 0 || bit > 7) {
		return;
	}
	if (value == true) {
		setByte(m_currentOutput | (1 << bit));
	} else {
		setByte(m_currentOutput & ~(1 << bit));
	}
} // End of setBit

/**
 * Write the value of the byte as the output of the GPIOs.
 */
void A85_PCF8574::setByte(uint8_t value) {
	// Guard that we have been initialized
	if (m_address == 0) {
		return;
	}
	m_currentOutput = value;
	TinyWireM.beginTransmission(m_address);
	TinyWireM.write(m_currentOutput);
	TinyWireM.endTransmission();
} // End of setByte

/**
 * Get the value of the byte of the GPIOs as input.
 */
uint8_t A85_PCF8574::getByte() {
	TinyWireM.requestFrom(m_address, 1);
	return TinyWireM.read();
} // End of getByte

/**
 * Get the value of the bit of the GPIO as input.
 */
bool A85_PCF8574::getBit(uint8_t bit) {
	if (bit < 0 || bit > 7) {
		return 0;
	}
	uint8_t byteValue = getByte();
	return (byteValue & (1<<bit)) != 0;
} // End of getBit
// End of file