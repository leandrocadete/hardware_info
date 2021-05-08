#ifndef NETWORK_ADAPTER_H
#define NETWORK_ADAPTER_H

#include "win32.h"
#include "DaoNetworkAdapterConfiguration.h"

class NetworkAdapter {
private:
	string Caption;
	string Description;
	string DeviceID;
	uint32_t Index;
	string MACAddress;
	string Manufacturer;
	string Name;
	//string* NetworkAddresses;
	bool PhysicalAdapter;	 
	uint64_t Speed;
	NetworkAdapterConfiguration networkAdapterConfiguration;
public:
	NetworkAdapter () {}
	~NetworkAdapter () {}
	string getCaption() { return Caption; }
	void setCaption(string v) { Caption = v; }
	string getDescription() { return Description; }
	void setDescription(string v) { Description = v; }
	string getDeviceID() { return DeviceID; }
	void setDeviceID(string v) { DeviceID = v; }
	uint32_t getIndex() { return Index; }
	void setIndex(uint32_t v) { Index = v; }
	string getMACAddress() { return MACAddress; }
	void setMACAddress(string v) { MACAddress = v; }
	string getManufacturer() { return Manufacturer; }
	void setManufacturer(string v) { Manufacturer = v; }
	string getName() { return Name; }
	void setName(string v) { Name = v; }
	//string* getNetworkAddresses() { return NetworkAddresses; }
	//void setNetWorkAddresses(string v[]) { NetworkAddresses = v; }
	bool getPhysicalAdapter() { return PhysicalAdapter; }
	void setPhysicalAdapter(bool v) { PhysicalAdapter = v; }
	uint64_t getSpeed() { return Speed; }
	void setSpeed(uint64_t v) { Speed = v; }
	NetworkAdapterConfiguration getNetworkAdapterConfiguration() { return networkAdapterConfiguration; }
	void setNetworkAdapterConfiguration(NetworkAdapterConfiguration v) { networkAdapterConfiguration = v; }
};

#endif