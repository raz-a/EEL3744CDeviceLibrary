/*
 * KeyPad.h
 *
 * Created: 6/18/2015 6:46:22 PM
 *  Author: Raz Aloni
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include "XmegaEnums.h"

namespace EEL3744C
{
	// Class to represent Keypad on Xmega
	class Keypad
	{
		public:
		
		Keypad(PORT_t &port, Out_Row_Col toKeypad, KP_OutNibble outNibble, ActivationLevel level);
		
		uint8_t Read();
		
		private:
		
		volatile register8_t * inPort;
		volatile register8_t * outPort;
		
		volatile uint8_t testRoundsOut[5] = {15,7,11,13,14};
		volatile uint8_t testRoundsIn[5] = {15 << 4, 7 << 4, 11 << 4, 13 << 4, 14 << 4};
		
		Out_Row_Col rowsOrColumns;
		uint8_t inNibble;
	};
}

#endif /* KEYPAD_H_ */