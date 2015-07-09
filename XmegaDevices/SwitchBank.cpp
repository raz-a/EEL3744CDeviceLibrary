/*
 * SwitchBank.cpp
 *
 * Created: 6/14/2015 12:34:18 AM
 *  Author: Raz Aloni
 */

#include "SwitchBank.h"

namespace EEL3744C
{
	SwitchBank::SwitchBank(PORT_t &port)
	{
		// Set input port
		this->inPort = &port.IN;
		
		// Set Port to input
		register8_t * dirPort = &port.DIR;
		*dirPort = 0x00;
	}

	uint8_t SwitchBank::Read()
	{
		return *this->inPort;
	}
}