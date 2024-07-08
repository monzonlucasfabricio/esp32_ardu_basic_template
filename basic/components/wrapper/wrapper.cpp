/*
 * wrapper.cpp
 *
 *  Created on: 8 jul 2024
 *      Author: Lucas
 */

#include "wrapper.h"


void WR_Println(char* message)
{
	Serial.println(message);
}

void WR_SerialBegin(uint32_t baudrate)
{
	Serial.begin(baudrate);
}

void WR_PinMode(uint8_t pin, uint8_t mode)
{
	pinMode(pin, mode);
}


