#ifndef DAO_MEMORY_H
#define DAO_MEMORY_H

//#include "Dao.h"
#include "../Model/win32.h"
#include "../Model/Memory.h"
#include "DaoPhysicalMemory.h"
#include <list>

class DaoMemory : private Win32Objs {
private:
	Memory *memory;

	void loadPhysicalMemory() {
        DaoPhysicalMemory *dao = new DaoPhysicalMemory();
        list<PhysicalMemory*> memories = dao->loadMemories();
		memory->setPhysicalMemories(memories);
	}
public:
	DaoMemory() {}
	~DaoMemory() {}

	Memory* loadData() {
		memory = new Memory();
		HRESULT hres = NULL;
		char win32_class[] = "SELECT * FROM Win32_OperatingSystem";
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return memory;
		IWbemClassObject* pclsObj;
		unsigned long uReturn = 0;

		if(pEnumerator) {
			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (uReturn == 0) return memory;
			VARIANT vtProp;
			string str;
//			uint64_t u64Values;

			hres = getString(L"FreePhysicalMemory", &vtProp, pclsObj, str);
			memory->setFreeSpace(_atoi64(str.c_str()));
		}
		release();
		loadPhysicalMemory();
		return memory;
	}

	Memory* getMemory() { return memory; }
};
#endif
