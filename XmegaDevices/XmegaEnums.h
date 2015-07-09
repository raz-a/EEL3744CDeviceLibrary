/*
 * XmegaEnums.h
 *
 * Created: 6/13/2015 10:45:43 PM
 *  Author: Raz Aloni
 */ 


#ifndef XMEGAENUMS_H_
#define XMEGAENUMS_H_

namespace EEL3744C
{	
	enum USART_STOPBITS : uint8_t
	{
		_1BIT = 0,
		_2BITS = 1	
	};
	
	enum ActivationLevel : uint8_t
	{
		Low_True,
		High_True	
	};

	enum ChipSelectValue : uint8_t
	{
		CS0 = 0x10,
		CS1 = 0x20,
		CS2	= 0x40,
		CS3 = 0x80
	};

	enum Out_Row_Col : uint8_t
	{
		Rows,
		Columns	
	};

	enum KP_OutNibble : uint8_t
	{
		TopNibble	= 0xF0,
		BottomNibble = 0x0F
	};
}
#endif /* XMEGAENUMS_H_ */