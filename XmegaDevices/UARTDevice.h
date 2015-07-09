/*
 * UARTDevice.h
 *
 * Created: 6/26/2015 11:07:55 PM
 *  Author: Raz Aloni
 */ 

#ifndef UARTDEVICE_H_
#define UARTDEVICE_H_

#include "XmegaEnums.h"

namespace EEL3744C
{	
	class UARTDevice
	{
		public:
		
		// Initializes a UART Device with some default settings
		UARTDevice(PORT_t &port) : UARTDevice(port, 9600, USART_CHSIZE_8BIT_gc, USART_PMODE_DISABLED_gc, _1BIT, USART_RXCINTLVL_OFF_gc){}
		
		// Initializes a UART Device
		UARTDevice(PORT_t &port, int baudrate, USART_CHSIZE_enum numberOfDataBits, USART_PMODE_enum parity,  USART_STOPBITS numberOfStopBits, USART_RXCINTLVL_enum receiveInterruptLevel);
		
		void Write(char string[]);
		void WriteLine(char string[]);
		
		char ReadByte();
		
		private:
		
		USART_t * usartPort;	//TODO: Is this right?
		void * interruptVector; //TODO: Is this right?
		
		void WriteChar(char c);
		
	};
}



#endif /* UARTDEVICE_H_ */