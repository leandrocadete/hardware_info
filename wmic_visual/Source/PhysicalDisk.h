#ifndef PHYSICALDISK_H
#define PHYSICALDISK_H

#include "win32.h"

#include "Partition.h"
#include <list>

class PhysicalDisk : public Win32_Wmi {
private:
	//uint16_t Availability;
	//uint32_t BytesPerSector;
	string Caption;
	string Description;
	string DeviceID;
	uint32_t Index;
	//string InstallDate;
	//string InterfaceType;
	string Manufacturer;
	//uint64_t MaxBlockSize;
	//uint64_t MaxMediaSize;
	//string MediaType;
	string Model;
	string Name;
	uint32_t PartitionsCount;
	string PNPDeviceID;
	uint32_t SectorsPerTrack;
	string SerialNumber;
	//uint32_t Signature;
	uint64_t Size;
	string Status;
	uint16_t StatusInfo;
	//string SystemName;
	uint64_t TotalCylinders;
	uint32_t TotalHeads;
	uint64_t TotalSectors;
	uint64_t TotalTracks;
	uint32_t TracksPerCylinder;
	list<Partition*> partitions;
public:
	//uint16_t getAvailability() { return Availability; }
	//uint32_t getBytesPerSector() { return BytesPerSector; }
	string getCaption() { return Caption; }
	string getDescription() { return Description; }
	string getDeviceID() { return DeviceID; }
	uint32_t getIndex() { return Index; }
	//string getInstallDate() { return InstallDate; }
	//string getInterfaceType() { return InterfaceType; }
	string getManufacturer() { return Manufacturer; }
	//uint64_t getMaxBlockSize() { return MaxBlockSize; }
	//uint64_t getMaxMediaSize() { return MaxMediaSize; }
	//string getMediaType() { return MediaType; }
	string getModel() { return Model; }
	string getName() { return Name; }
	uint32_t getPartitionsCount() { return PartitionsCount; }
	string getPNPDeviceID() { return DeviceID; }
	uint32_t getSectorsPerTrack() { return SectorsPerTrack; }
	string getSerialNumber() { return SerialNumber; }
	//uint32_t getSignature() { return Signature; }
	uint64_t getSize() { return Size; }
	string getStatus() { return Status; }
	uint16_t getStatusInfo() { return StatusInfo; }	
	//string getSystemName() { return SystemName; }
	uint64_t getTotalCylinders() { return TotalCylinders; }
	uint32_t getTotalHeads() { return TotalHeads; }
	uint64_t getTotalSectors() { return TotalSectors; }
	uint64_t getTotalTracks() { return TotalTracks; }
	uint32_t getTracksPerCylinder() { return TracksPerCylinder; }
	list<Partition*> getPartitions() { return partitions; }

	//void setAvailability(uint16_t v) { Availability = v; }
	//void setBytesPerSector(uint32_t v) { BytesPerSector = v; }
	void setCaption(string v) { Caption = v; }
	void setDescription(string v) { Description = v; }
	void setDeviceID(string v) { DeviceID = v; }
	void setIndex(uint32_t v) { Index = v; }
	//void setInstallDate(string v) { InstallDate = v; }
	//void setInterfaceType(string v) { InterfaceType = v; }
	void setManufacturer(string v) { Manufacturer = v; }
	//void setMaxBlockSize(uint64_t v) { MaxBlockSize = v; }
	//void setMaxMediaSize(uint64_t v) { MaxMediaSize= v; }
	//void setMediaType(string v) { MediaType= v; }
	void setModel(string v) { Model= v; }
	void setName(string v) { Name = v; }
	void setPartitionsCount(uint32_t v) { PartitionsCount = v; }
	void setPNPDeviceID(string v) { PNPDeviceID = v; }
	void setSectorsPerTrack(uint32_t v) { SectorsPerTrack = v; }
	void setSerialNumber(string v) { SerialNumber = v; }
	//void setSignature(uint32_t v) { Signature = v; }
	void setSize(uint64_t v) { Size = v; }
	void setStatus(string v) { Status = v; }
	void setStatusInfo(uint16_t v) { StatusInfo = v; }	
	//void setSystemName(string v) { SystemName = v; }
	void setTotalCylinders(uint64_t v) { TotalCylinders = v; }
	void setTotalHeads(uint32_t v) { TotalHeads = v; }
	void setTotalSectors(uint64_t v) { TotalSectors = v; }
	void setTotalTracks(uint64_t v) { TotalTracks = v; }
	void setTracksPerCylinder(uint32_t v) { TracksPerCylinder = v; }
	void setPartitions(list<Partition*> v) { partitions = v; }
};

#endif