/*
 * LEDBar.cpp
 *
 * Created: 6/13/2015 11:11:43 PM
 *  Author: Raz Aloni
 */ 

#include <avr/io.h>
#include "LEDBar.h"

namespace EEL3744C
{
	LEDBar::LEDBar(PORT_t &port, ActivationLevel level)
	{
		// Set activation level
		this->level = level;
		
		// Set output port
		this->outPort = &port.OUT;
		
		// Set Port to output
		register8_t * dirPort = &port.DIR;
		*dirPort = 0xFF;
	}

	void LEDBar::Display(uint8_t value)
	{
		*this->outPort = (this->level == Low_True) ? ~value : value;
	}
}