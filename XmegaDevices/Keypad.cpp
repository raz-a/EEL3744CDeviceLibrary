/*
 * Keypad.cpp
 *
 * Created: 6/18/2015 7:00:35 PM
 *  Author: Raz Aloni
 */ 

#include "KeyPad.h"

namespace EEL3744C
{
	Keypad::Keypad(PORT_t &port, Out_Row_Col toKeypad, KP_OutNibble outNibble, ActivationLevel level)
	{
		// Get input/output ports
		this->outPort = &port.OUT;
		this->inPort = &port.IN;
		
		register8_t * dirPort = &port.DIR;
		
		*dirPort = outNibble;
		this->inNibble = ~outNibble;
		
		/* Default: pull-ups, output is on lower half */
		
		// Pull-downs
		if (level == High_True)
		{
			for (int i = 0; i < 5; i++)
			{
				this->testRoundsOut[i] = (~this->testRoundsOut[i]) & 0x0F;
				this->testRoundsIn[i] = (~this->testRoundsIn[i]) & 0xF0;
			}
		}
		
		// output is on upper half
		if (outNibble == TopNibble)
		{
			for (int i = 0; i < 5; i++)
			{
				uint8_t temp = this->testRoundsIn[i];
				this->testRoundsIn[i] = this->testRoundsOut[i];
				this->testRoundsOut[i] = temp;
			}
		}
		
		// Set default output
		*this->outPort = testRoundsOut[0];
		
		// Save is output is rows or columns
		this->rowsOrColumns = toKeypad;
	}

	uint8_t Keypad::Read()
	{
		uint8_t inValue;
		
		// Wait until a value is pushed
		while(1)
		{
			for(int i = 1; i < 5; i++)
			{
				*this->outPort = this->testRoundsOut[i];
				
				// Delays
				asm("nop");
				asm("nop");
				asm("nop");
				
				inValue = *this->inPort & inNibble;
				
				for(int j = 1; j < 4; j++)
				{
					if (inValue == testRoundsIn[j])
					{
						if (rowsOrColumns == Rows)
						{
							return i == 4? 14 : (3*i)+(j-3); //1,4,7,14
						}
						return i == 4? 9+j : i + (3*(j-1)); //1,2,3,10
					}
				}
				
				if (inValue == testRoundsIn[4])
				{
					if (rowsOrColumns == Rows)
					{
						return 9 + i; //10,11,12,13
					}
					switch (i)
					{
						case(1): return 14;
						case(2): return 0;
						case(3): return 15;
						case(4): return 13;
					} //14,0,15,13
				}
			}
		}
	}
}