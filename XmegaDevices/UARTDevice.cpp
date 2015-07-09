/*
 * UARTDevice.cpp
 *
 * Created: 6/27/2015 12:38:25 AM
 *  Author: Raz Aloni
 */ 

#include <avr/interrupt.h>
#include "UARTDevice.h"

namespace EEL3744C
{
	UARTDevice::UARTDevice(PORT_t &port, int baudrate, USART_CHSIZE_enum numberOfDataBits, USART_PMODE_enum parity,  USART_STOPBITS numberOfStopBits, USART_RXCINTLVL_enum receiveInterruptLevel)
	{
		//TODO: Calc BAUDRate
		//TODO: Determine USART_t
		//TODO: Set Interrupt Vector
		//TODO: Set USART_t values
		//TODO: New Enums (UARTPORT, USART0/1)
	}
}