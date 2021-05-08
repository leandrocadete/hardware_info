#ifndef PHYSICAL_MEMORY_H
#define PHYSICAL_MEMORY_H

#include "win32.h"

class PhysicalMemory {
private:
	
	uint32_t Attributes;
	string BankLabel;
	uint64_t Capacity;
	string Caption;
	//uint32_t ConfiguredClockSpeed;
	//uint32_t ConfiguredVoltage;
	//string CreationClassName;
	uint16_t DataWidth;
	string Description;
	string DeviceLocator;
	uint16_t FormFactor;
	//boolean HotSwappable;
	//datetime InstallDate;
	//uint16_t InterleaveDataDepth;
	//uint32_t InterleavePosition;
	string Manufacturer;
	//uint32_t MaxVoltage;
	//uint16_t MemoryType;
	//uint32_t MinVoltage;
	//string Model;
	//string Name;
	//string OtherIdentifyingInfo;
	//string PartNumber;
	uint32_t PositionInRow;
	//boolean PoweredOn;
	//boolean Removable;
	//boolean Replaceable;
	string SerialNumber;
	//string SKU;
	//uint32_t SMBIOSMemoryType;
	uint32_t Speed;
	//string Status;
	string Tag;
	uint16_t TotalWidth;
	uint16_t TypeDetail;
	//string Version;
public:
	PhysicalMemory() {}
	~PhysicalMemory() {}
	uint32_t getAttributes() { return Attributes; }
	void setAttributes(uint32_t v) { Attributes = v; }
	string getBankLabel() { return BankLabel; }
	void setBankLabel(string v) { BankLabel = v; }
	uint64_t getCapacity() { return Capacity; }
	void setCapacity(uint64_t v) { Capacity = v; }
	string getCaption() { return Caption; }
	void setCaption(string v) { Caption = v; }
	uint16_t getDataWidth() { return DataWidth; }
	void setDataWidth(uint16_t v) { DataWidth = v; }
	string getDescription() { return Description; }
	void setDescription(string v) { Description = v; }
	string getDeviceLocator() { return DeviceLocator; }
	void setDeviceLocator(string v) { DeviceLocator = v; }
	uint16_t getFormFactor() { return FormFactor; }
	void setFormFactor(uint16_t v) { FormFactor = v; }
	string getManufacturer() { return Manufacturer; }
	void setManufacturer(string v) { Manufacturer = v; }
	uint32_t getPositionInRow() { return PositionInRow; }
	void setPositionInRow(uint32_t v) { PositionInRow = v; }
	string getSerialNumber() { return SerialNumber; }
	void setSerialNumber(string v) { SerialNumber = v; }
	uint32_t getSpeed() { return Speed; }
	void setSpeed(uint32_t v) { Speed = v; }
	string getTag() { return Tag; }
	void setTag(string v) { Tag = v; }
	uint16_t getTotalWidth() { return TotalWidth; }
	void setTotalWidth(uint16_t v) { TotalWidth = v; }
	uint16_t getTypeDetail() { return TypeDetail; }
	void setTypeDetail(uint16_t v) { TypeDetail = v; }
};

#endif