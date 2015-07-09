/*
 * EBIDevice.cpp
 *
 * Created: 6/18/2015 2:06:19 AM
 *  Author: Raz Aloni
 */ 

#include "EBIDevice.h"

namespace EEL3744C
{
	EBIDevice::EBIDevice(uint32_t startingAddress, uint32_t sizeInAddresses, ChipSelectValue cs)
	{
		PORTH.DIRSET = cs | 0x7; // Configure RE,WE,ALE1, and CS0/1/2 as output
		PORTH.OUTSET = cs | 0x3;	// Set default false values
		
		PORTK.DIRSET = 0xFF;		// Set Address ports to output
		
		EBI.CTRL = EBI_SRMODE_ALE1_gc | EBI_IFMODE_3PORT_gc;	// Set EBI_CTRL to be in 3 Port SRAM ALE1 Mode
		
		this->startingAddress = startingAddress;
		this->size = sizeInAddresses;
		
		// Set CS location and size (and SRAM Mode)
		this->setCSBoundary(cs);
	}

	void EBIDevice::setCSBoundary(ChipSelectValue cs)
	{
		volatile uint16_t * csBaseAddr;
		volatile uint8_t * csCtrlA;
		
		switch(cs)
		{
			case CS0:
			csBaseAddr = &EBI.CS0.BASEADDR;
			csCtrlA = &EBI.CS0.CTRLA;
			break;
			case CS1:
			csBaseAddr = &EBI.CS1.BASEADDR;
			csCtrlA = &EBI.CS1.CTRLA;
			break;
			case CS2:
			csBaseAddr = &EBI.CS2.BASEADDR;
			csCtrlA = &EBI.CS2.CTRLA;
			break;
			case CS3:
			csBaseAddr = &EBI.CS3.BASEADDR;
			csCtrlA = &EBI.CS3.CTRLA;
			break;
		}
		
		uint8_t regSize = 16;
		uint8_t shiftSize = 23;
		uint32_t endingAddress = this->startingAddress + size - 1;
		while(((this->startingAddress >> shiftSize) & 1) == ((endingAddress >> shiftSize) & 1))
		{
			shiftSize--;
			regSize--;
		}
		
		*csCtrlA = regSize << 2 | EBI_CS_MODE_SRAM_gc;
		*csBaseAddr = this->startingAddress >> 8;
	}

	void EBIDevice::Write(uint8_t value, uint32_t address)
	{
		if (address < size)
		{
			address += this->startingAddress;
			uint8_t *memLocation = (uint8_t *)address;
			
			*memLocation = value;
		}
	}

	void EBIDevice::Write(uint8_t value)
	{
		this->Write(value, 0);
	}

	uint8_t EBIDevice::Read(uint32_t address)
	{
		if (address < size)
		{
			address += this->startingAddress;
			uint8_t *memLocation = (uint8_t *)address;
			
			return *memLocation;
		}
		
		return 0;
	}

	uint8_t EBIDevice::Read()
	{
		return this->Read(0);
	}
}