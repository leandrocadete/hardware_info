#ifndef DAO_NETWORK_ADAPTER_CONFIGURATION_H
#define DAO_NETWORK_ADAPTER_CONFIGURATION_H

#include "win32.h"
#include "NetworkAdapterConfiguration.h"
#include <list>

class DaoNetworkAdapterConfiguration : private Win32Objs {
private:
	list<NetworkAdapterConfiguration*> netWorkAdapters;
	NetworkAdapterConfiguration* netWorkAdapter;
public:
	DaoNetworkAdapterConfiguration() {}
	~DaoNetworkAdapterConfiguration() {}
	list<NetworkAdapterConfiguration*> getNetworkAdapterConfiguration() { return netWorkAdapters; }
	list<NetworkAdapterConfiguration*> loadData() {
		HRESULT hres = NULL;
		char win32_class[] = "SELECT * FROM win32_networkadapterconfiguration where IPEnabled=True";		
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return netWorkAdapters;
		IWbemClassObject* pclsObj;
		unsigned long int uReturn = 0;
		while(pEnumerator) {
			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if(uReturn == NULL) break;
			netWorkAdapter = new NetworkAdapterConfiguration();
			VARIANT vtProp;
			bool bvalue = false;
			string str;
			string *strArrays = NULL;
			int int32;
			vector<char*> c_DefaultIPGateway = getVectorChars(L"DefaultIPGateway", &vtProp, pclsObj, hres);
			netWorkAdapter->setDefaultIPGateway(c_DefaultIPGateway);
			hres = getString(L"DHCPLeaseExpires", &vtProp, pclsObj, str);
			netWorkAdapter->setDHCPLeaseExpires(str);
			hres = getString(L"DHCPLeaseObtained", &vtProp, pclsObj, str);
			netWorkAdapter->setDHCPLeaseObtained(str);
			hres = getString(L"DHCPServer", &vtProp, pclsObj, str);
			netWorkAdapter->setDHCPServer(str.c_str());
			hres = getString(L"DNSHostName", &vtProp, pclsObj, str);
			netWorkAdapter->setDNSHostName(str);
			vector<char*> c_DNSServerSearchOrder = getVectorChars(L"DNSServerSearchOrder", &vtProp, pclsObj, hres);
			netWorkAdapter->setDNSServerSearchOrder(c_DNSServerSearchOrder);
			vector<char*> c_IPAddress = getVectorChars(L"IPAddress", &vtProp, pclsObj, hres);
			netWorkAdapter->setIPAddress(c_IPAddress);
			vector<char*> c_IPSubnet = getVectorChars(L"IPSubnet", &vtProp, pclsObj, hres);
			netWorkAdapter->setIPSubnet(c_IPSubnet);
			hres = getBoolean(L"DomainDNSRegistrationEnabled", &vtProp, pclsObj, bvalue);
			netWorkAdapter->setDomainDNSRegistrationEnabled(bvalue);
			hres = getInt32(L"Index", &vtProp, pclsObj, int32);
			netWorkAdapter->setIndex(int32);
			netWorkAdapters.push_back(netWorkAdapter);
		}
		release();
		return netWorkAdapters;
	}
};

#endif