#ifndef DAO_NETWORK_ADAPTER
#define DAO_NETWORK_ADAPTER

#include "win32.h"
#include "NetworkAdapter.h"
#include "DaoNetworkAdapterConfiguration.h"
#include <list>

class DaoNetworkAdapter : private Win32Objs {
private:
	list<NetworkAdapter*> adapters;
	NetworkAdapter *adapter;
public:
	DaoNetworkAdapter () {};
	~DaoNetworkAdapter () {};
	list<NetworkAdapter*> getNetworkadapters() { return adapters; }
	list<NetworkAdapter*> loadData() {		
		HRESULT hres = NULL;
		char win32_class[] = "SELECT * FROM Win32_NetworkAdapter Where PhysicalAdapter = true";
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return adapters;
		IWbemClassObject* pclsObj;
		unsigned long int uReturn = 0;
		while(pEnumerator) {
			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if(uReturn == 0) break;
			adapter = new NetworkAdapter();
			VARIANT vtProp;
			bool bvalue = false;
			string str;
			string *strArray = NULL;
			uint16_t u16V;
			uint32_t u32V;
			uint64_t u64V;
			hres = getBoolean(L"PhysicalAdapter", &vtProp, pclsObj, bvalue);
			adapter->setPhysicalAdapter(bvalue);
			hres = getString(L"Caption", &vtProp, pclsObj, str);
			adapter->setCaption(str);
			hres = getString(L"Description", &vtProp, pclsObj, str);
			adapter->setDescription(str);
			hres = getString(L"DeviceID", &vtProp, pclsObj, str);
			adapter->setDeviceID(str);
			hres = getuInt16(L"Index", &vtProp, pclsObj, u16V);
			adapter->setIndex(u16V);
			hres = getString(L"MACAddress", &vtProp, pclsObj, str);
			adapter->setMACAddress(str);
			hres = getString(L"Manufacturer", &vtProp, pclsObj, str);
			adapter->setManufacturer(str);
			hres = getString(L"Name", &vtProp, pclsObj, str);
			adapter->setName(str);
			hres = getuInt64(L"Speed", &vtProp, pclsObj, u64V);
			adapter->setSpeed(u64V);

			adapters.push_back(adapter);			
		}
		release();
		list<NetworkAdapter*>::iterator iter = adapters.begin();
		list<NetworkAdapter*>::iterator iterEnd = adapters.end();

		DaoNetworkAdapterConfiguration *dao = new DaoNetworkAdapterConfiguration();
		list<NetworkAdapterConfiguration*> nacs;

		nacs = dao->loadData();

		while(iter != iterEnd) {
			int index = (*iter)->getIndex();
			list<NetworkAdapterConfiguration*>::iterator iter2 = nacs.begin();
			list<NetworkAdapterConfiguration*>::iterator iterEnd2 = nacs.end();
			while(iter2 != iterEnd2) {
				int index2 = (*iter2)->getIndex();
				NetworkAdapterConfiguration n =  *(*iter2);
				if(index == index2) {
					(*iter)->setNetworkAdapterConfiguration(n);
					break;
				}
				iter2++;
			}
			iter++;
		}
		return adapters;
	}
};

#endif