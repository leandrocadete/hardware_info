#ifndef NETWORK_ADAPTER_CONFIGURATION_H
#define NETWORK_ADAPTER_CONFIGURATION_H

#include "win32.h"
#include <vector>

class NetworkAdapterConfiguration {
private:	
	string DHCPLeaseExpires;
	string DHCPLeaseObtained;
	char DHCPServer[15];
	string DNSHostName;
	int Index;
	bool DomainDNSRegistrationEnabled;

	vector<char*> DefaultIPGateway; // char[2][39]
	vector<char*> IPAddress; // char[2][39]
	vector<char*> DNSServerSearchOrder; // char[2][39]	
	vector<char*> IPSubnet; // char[2][39]
	
	int sizeArrays;
public:
	~NetworkAdapterConfiguration() {}
	NetworkAdapterConfiguration() {
		sizeArrays = 2;
		/*DefaultIPGateway = new char*[2];
		IPAddress = new char*[2];
		DNSServerSearchOrder = new char*[2];
		IPSubnet = new char*[2];

		for (int i = 0; i < sizeArrays; i++)	{
			DefaultIPGateway[i] = new char[39];
			IPAddress[i] = new char[39];
			DNSServerSearchOrder[i] = new char[39];
			IPSubnet[i] = new char[39];
		}*/
	}
	void setSizeArrays(unsigned int size) { sizeArrays = size; }
	void setDHCPLeaseExpires(string v) { DHCPLeaseExpires = v; }
	string getDHCPLeaseExpires() { return DHCPLeaseExpires; }
	void setDHCPLeaseObtained(string v) { DHCPLeaseObtained = v; }
	string getDHCPLeaseObtained() { return DHCPLeaseObtained; }
	void setDHCPServer(const char* v) { strcpy(DHCPServer, v); }
	char* getDHCPServer() { return DHCPServer; }
	void setDNSHostName(string v) { DNSHostName = v; }
	string getDNSHostName() { return DNSHostName; }
	void setIndex(int v) { Index = v; }
	int getIndex() { return Index; }

	void setDefaultIPGateway(vector<char*> v) { 
		/*for (int i = 0; i  < sizeArrays; i ++) {
			strcpy(DefaultIPGateway[i], v[i]);
		}*/
		DefaultIPGateway = v;
	} // char[2][39]
	vector<char*> getDefaultIPGateway() { return DefaultIPGateway; }
	void setIPAddress(vector<char*> v) {
		IPAddress = v;
		/*for (int i = 0; i < sizeArrays; i++) {
			strcpy(IPAddress[i], v[i]);
		}*/
		
	} // char[2][39]
	vector<char*> getIPAddress() { return IPAddress; } // char[2][39]
	void setDNSServerSearchOrder(vector<char*> v) { 
		/*for (int i = 0; i < sizeArrays; i++) {
			strcpy(DNSServerSearchOrder[i], v[i]);
		} */// char[2][39]
		DNSServerSearchOrder = v;
	}
	vector<char*> getDNSServerSearchOrder() { return DNSServerSearchOrder; } // char[2][39]
	void setIPSubnet(vector<char*> v) {
		/*for (int i = 0; i < sizeArrays; i++) {
			strcpy(IPSubnet[i], v[i]);
		}*/
		DNSServerSearchOrder = v;
	} // char[2][39]
	vector<char*> getIPSubnet() { return IPSubnet; } // char[2][39]

	void setDomainDNSRegistrationEnabled(bool v) { DomainDNSRegistrationEnabled = v; }
	bool getDomainDNSRegistrationEnabled() { return DomainDNSRegistrationEnabled; }
};

#endif