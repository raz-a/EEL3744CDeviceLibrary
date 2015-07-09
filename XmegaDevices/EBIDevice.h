/*
 * EBIDevice.h
 *
 * Created: 6/18/2015 1:43:39 AM
 *  Author: Raz Aloni
 */ 

#ifndef EBIDEVICE_H_
#define EBIDEVICE_H_

#include <avr/io.h>
#include "XmegaEnums.h"

namespace EEL3744C
{
	// Class to represent devices connected to EBI
	class EBIDevice
	{
		public:
		
		// Initializes an EBI device of given starting address, size, and CS location
		EBIDevice(uint32_t startingAddress, uint32_t sizeInAddresses, ChipSelectValue cs);
		
		// Writes value to EBI device at a given relative address
		void Write(uint8_t value, uint32_t address);
		
		// Writes value to EBI device at starting address
		void Write(uint8_t value);
		
		// Reads value from EBI device at a given relative address
		uint8_t Read(uint32_t address);
		
		// Reads value from EBI device at starting address
		uint8_t Read();
		
		protected:
		
		//sets the correct boundary for a CS
		void setCSBoundary(ChipSelectValue cs);
		
		uint32_t startingAddress;
		uint32_t size;
	};
}

#endif /* EBIDEVICE_H_ */