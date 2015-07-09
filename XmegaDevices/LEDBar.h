/*
 * LEDBar.h
 *
 * Created: 6/13/2015 10:52:26 PM
 *  Author: Raz Aloni
 */ 

#ifndef LEDBAR_H_
#define LEDBAR_H_

#include <avr/io.h>
#include "XmegaEnums.h"

namespace EEL3744C
{
	// Class to represent 8-bit LED Bar
	class LEDBar
	{
		public:
		
		// Initializes an LED bar to a given port
		LEDBar(PORT_t &port) : LEDBar(port, High_True){}
		
		// Initializes an LED bar to a given port with a given activation level
		LEDBar(PORT_t &port, ActivationLevel level);
		
		// Displays an 8 bit value to the LED bar
		void Display(uint8_t value);
		
		private:
		
		// Pointer to PORT_OUT on XMEGA
		register8_t * outPort;
		
		// Activation level of LEDS
		ActivationLevel level;
	};
}

#endif /* LEDBAR_H_ */