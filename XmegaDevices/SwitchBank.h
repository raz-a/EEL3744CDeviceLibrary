/*
 * SwitchBank.h
 *
 * Created: 6/14/2015 12:23:52 AM
 *  Author: Raz Aloni
 */ 

#ifndef SWITCHBANK_H_
#define SWITCHBANK_H_

#include <avr/io.h>
#include "XmegaEnums.h"

namespace EEL3744C
{
	// Class to represent 8-bit DIP SwitchBank
	class SwitchBank
	{
		public:
		
		// Initializes a SwitchBank to a given port
		SwitchBank(PORT_t &port);

		// Reads the switch values
		uint8_t Read();

		private:
		
		// Pointer to PORT_IN on XMEGA
		register8_t * inPort;
	};
}

#endif /* SWITCHBANK_H_ */