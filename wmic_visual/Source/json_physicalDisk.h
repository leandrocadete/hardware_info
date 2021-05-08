#ifndef JSON_PHYSICALDISK_H
#define JSON_PHYSICALDISK_H
//#include "AbstractTest.h"
#include "DaoPhysicalDisk.h"
#include <string>
#include "abstJson.h"

class JsonPhysicalDisk /*: public AbsTest*/ {
private:
	DaoPhysicalDisk *dao;
	PhysicalDisk *disk;
	list<PhysicalDisk*> disks;
	ofstream *file;
public:
    JsonPhysicalDisk(ofstream *f) {
		file = f;
		dao = new DaoPhysicalDisk();
	}
    ~JsonPhysicalDisk(){
		cout << "Objeto JsonPhysicalDisk destruido" << endl;
	}
	bool jsonInit() {
		dao->loadData();
		if(dao->getPhysicalDisks().empty()) {
			cerr << "Falha ao coletar discos ou não existe disco neste sistema operacional!" << endl;
			return false;
		}
		disks = dao->getPhysicalDisks();
		return true;
	}

	bool gererateJson () {
		cout << "**********************************************************************************" << endl;
		cout << "************Json de unidade físicas/armazenamento (Discos) iniciado!*************" << endl;
		cerr << "************Json de unidade físicas/armazenamento (Discos) iniciado!*************" << endl;
		cout << "**********************************************************************************" << endl;
		bool flag = true;
		flag = jsonInit();
		list<PhysicalDisk*>::iterator iter = disks.begin();
		list<PhysicalDisk*>::iterator iterEnd = disks.end();
		*file << "\"PhysicalDisks\": [" << endl;

		while(iter != iterEnd) {
			disk = *iter;
			cout << "----------------------------------------------------------------------------------" << endl;
			*file << "{" << endl;

			attCaption();
			attDescription();
			attDeviceID();
			attIndex();
			attManufacturer();
			attModel();
			attName();
			attPartitions();
			attPNPDeviceID();
			attSectorsPerTrack();
			attSerialNumber();
			attSize();
			attStatus();
			attStatusInfo();
			attTotalCylinders();
			attTotalHeads();
			attTotalSectors();
			attTotalTracks();
			attTracksPerCylinder();
			iter++;
			cout << "----------------------------------------------------------------------------------" << endl;
			if(iter == iterEnd) {
                *file << "}\n";
            } else {
                *file << "},\n";
            }
		}
		*file << "]" << endl;
		if(flag) cout << "JSON de PhysicalDisks OK!" << endl;
		else cerr << "JSON de PhysicalDisks falhou!" << endl;
		cout << "**********************************************************************************" << endl;
		return flag;
	}

	void attCaption() {			
		*file << printString("Caption", disk->getCaption());
	}
	void attDescription() {
		*file << printString("Description", disk->getDescription());
	}
	void attDeviceID() {		
		*file << printString("DeviceID", disk->getDeviceID());
	}
	void attIndex() {		
		*file << printUint32("Index", disk->getIndex());
	}
	void attManufacturer() {
		*file << printString("Manufacturer", disk->getManufacturer());
	}
	void attModel() {		
		*file << printString("Model", disk->getModel());
	}
	void attName() {
		*file << printString("Name", disk->getName());
	}
	void attPartitions() {		
		list<Partition*>parts = disk->getPartitions();
		list<Partition*>::iterator iter = parts.begin();
		list<Partition*>::iterator end = parts.end();
		for(; iter != end; iter++) {
			//*file << printString(".........................................................................", endl;
			*file << printString("Letter", (*iter)->getLetter());
			*file << printString("VolumeName",(*iter)->getVolumeName());
			//*file << printString(".........................................................................", endl;
		}
	}
	void attPartitionsCount() {
		*file << printUint32("Partitions", disk->getPartitionsCount());
	}
	void attPNPDeviceID() {
		*file << printString("PNPDeviceID", disk->getPNPDeviceID());
	}
	void attSectorsPerTrack() {
		*file << printUint32("SectorsPerTrack", disk->getSectorsPerTrack());
	}
	void attSerialNumber() {
		*file << printString("Serial", disk->getSerialNumber()); 
	}
	void attSize() {
		*file << printUint64("Size", disk->getSize());
	}
	void attStatus() {
		*file << printString("Status", disk->getStatus());
	}
	void attStatusInfo() {
		*file << printUint16("StatusInfo", disk->getStatusInfo());
	}
	void attTotalCylinders() {
		*file << printUint64("TotalCylinders", disk->getTotalCylinders());
	}
	void attTotalHeads() {
		*file << printUint32("TotalHeads", disk->getTotalHeads());
	}
	void attTotalSectors() {
		*file << printUint64("TotalSectors", disk->getTotalSectors());
	}
	void attTotalTracks() {
		*file << printUint64("TotalTracks", disk->getTotalTracks());
	}
	void attTracksPerCylinder() {
		*file << printUint32("TracksPerCylinder", disk->getTracksPerCylinder());
	}
};

#endif