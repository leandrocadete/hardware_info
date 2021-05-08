#ifndef DAO_PHYSICAL_MEMORY_H
#define DAO_PHYSICAL_MEMORY_H


#include <list>
//#include "Dao.h"
#include "win32.h"
#include "PhysicalMemory.h"

class DaoPhysicalMemory : private Win32Objs {
private:
	list<PhysicalMemory*> memories;
	PhysicalMemory *memory;
public:
	DaoPhysicalMemory() {}
	~DaoPhysicalMemory() {}
	//list<PhysicalMemory*> getMemories() { return memories; }

	list<PhysicalMemory*> loadMemories() {
		char win32_class[] = "SELECT * FROM Win32_PhysicalMemory";
		HRESULT hres = NULL;
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return memories;
		IWbemClassObject* pclsObj;
		unsigned long uReturn = 0;
		while(pEnumerator) {
			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if(uReturn == 0) break;
			VARIANT vtProp;
			string str;
			uint32_t u32Value;
			uint16_t u16Value;
//			uint64_t u64Value;			
			memory = new PhysicalMemory();
			//hres = getuInt32(L"Attributes", &vtProp, pclsObj, u32Value);
			//memory->setAttributes(u32Value);
			hres = getString(L"BankLabel", &vtProp, pclsObj, str);
			memory->setBankLabel(str);
			hres = getString(L"Capacity", &vtProp, pclsObj, str);
			memory->setCapacity(_atoi64(str.c_str()));
			hres = getString(L"Caption", &vtProp, pclsObj, str);
			memory->setCaption(str);
			hres = getuInt16(L"DataWidth", &vtProp, pclsObj, u16Value);
			memory->setDataWidth(u16Value);
			hres = getString(L"Description", &vtProp, pclsObj, str);
			memory->setDescription(str);
			hres = getString(L"DeviceLocator", &vtProp, pclsObj, str);
			memory->setDeviceLocator(str);
			hres = getuInt16(L"FormFactor", &vtProp, pclsObj, u16Value);
			memory->setFormFactor(u16Value);
			hres = getString(L"Manufacturer", &vtProp, pclsObj, str);
			memory->setManufacturer(str);
			hres = getuInt32(L"PositionInRow", &vtProp, pclsObj, u32Value);
			memory->setPositionInRow(u32Value);
			hres = getString(L"SerialNumber", &vtProp, pclsObj, str);
			memory->setSerialNumber(str);
			hres = getuInt32(L"Speed", &vtProp, pclsObj, u32Value);
			memory->setSpeed(u32Value);
			hres = getString(L"Tag", &vtProp, pclsObj, str);
			memory->setTag(str);
			hres = getuInt16(L"TotalWidth", &vtProp, pclsObj, u16Value);
			memory->setTotalWidth(u16Value);
			hres = getuInt16(L"TypeDetail", &vtProp, pclsObj, u16Value);
			memory->setTypeDetail(u16Value);

			memories.push_back(memory);
		}
		gpSvc->Release();
		gpLoc->Release();
		CoUninitialize();
		return memories;
	}
};

#endif