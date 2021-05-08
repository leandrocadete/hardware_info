#ifndef DAOPHYSICALDISK_H
#define DAOPHYSICALDISK_H

#include "Dao.h"
#include "win32.h"
//#include "PhysicalDisk.h"
//#include "DaoPartition.h"
#include <list>

class DaoPhysicalDisk : private Win32Objs {
private:
	list<PhysicalDisk*> disks;
	PhysicalDisk *disk;
	DaoPartition *daoPartition;
public:
	DaoPhysicalDisk(){}
	~DaoPhysicalDisk(){}
	list<PhysicalDisk*> getPhysicalDisks() { return disks; }

	int loadData() {
		char win32_class[] = "SELECT * FROM Win32_DiskDrive";
		HRESULT hres = NULL;
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return 1;
		IWbemClassObject* pclsObj;
		ULONG uReturn = 0;
		while (pEnumerator) {
			hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
			if (uReturn == 0) break;
			VARIANT vtProp;
			string str;
			uint32_t uint32Value;
			uint16_t uint16Value;
			uint64_t uint64Value;
			disk = new PhysicalDisk();			
			hres = getString(L"Caption", &vtProp, pclsObj, str);
			disk->setCaption(str);
			hres = getString(L"Description", &vtProp, pclsObj, str);
			disk->setDescription(str);
			hres = getString(L"DeviceID", &vtProp, pclsObj, str);
			disk->setDeviceID(str);
			hres = getuInt32(L"Index", &vtProp, pclsObj, uint32Value);
			disk->setIndex(uint32Value);			
			hres = getString(L"Manufacturer", &vtProp, pclsObj, str);
			disk->setManufacturer(str);
			hres = getString(L"Model", &vtProp, pclsObj, str);
			disk->setModel(str);
			hres = getString(L"Name", &vtProp, pclsObj, str);
			disk->setName(str);
			hres = getuInt32(L"Partitions", &vtProp, pclsObj, uint32Value);
			disk->setPartitionsCount(uint32Value);
			hres = getString(L"PNPDeviceID", &vtProp, pclsObj, str);
			disk->setPNPDeviceID(str);
			hres = getuInt32(L"SectorsPerTrack", &vtProp, pclsObj, uint32Value);
			disk->setSectorsPerTrack(uint32Value);
			hres = getString(L"SerialNumber", &vtProp, pclsObj, str);
			disk->setSerialNumber(str);
			hres = getString(L"Size", &vtProp, pclsObj, str);
			disk->setSize(_atoi64(str.c_str()));
			hres = getString(L"Status", &vtProp, pclsObj, str);
			disk->setStatus(str);
			hres = getuInt16(L"StatusInfo", &vtProp, pclsObj, uint16Value);
			disk->setStatusInfo(uint16Value);
			hres = getString(L"TotalCylinders", &vtProp, pclsObj, str);
			disk->setTotalCylinders(_atoi64(str.c_str()));
			hres = getuInt32(L"TotalHeads", &vtProp, pclsObj, uint32Value);
			disk->setTotalHeads(uint32Value);
			hres = getString(L"TotalSectors", &vtProp, pclsObj, str);
			disk->setTotalSectors(_atoi64(str.c_str()));
			hres = getString(L"TotalTracks", &vtProp, pclsObj, str);
			disk->setTotalSectors(_atoi64(str.c_str()));
			hres = getuInt64(L"TracksPerCylinder", &vtProp, pclsObj, uint64Value);
			disk->setTotalSectors(uint64Value);
			disks.push_back(disk);
		}
		hres = NULL;
		gpSvc->Release();
		gpLoc->Release();
		CoUninitialize();
		DaoPartition daoPartition;
		list <PhysicalDisk*>::iterator iter;
		list <PhysicalDisk*>::iterator endIter;
		iter = disks.begin();
		endIter = disks.end();
		while (iter != endIter) {
			BSTR bstr =_com_util::ConvertStringToBSTR((*iter)->getDeviceID().c_str());
			const _bstr_t wrapper(bstr, true);
			wstring deviceid((const __wchar_t*) wrapper);
			(*iter)->setPartitions(daoPartition.loadPartitions(deviceid, hres));
			iter++;
		}
		return 0;
	}
}; 

#endif