#ifndef TEST_PHYSICAL_DISK
#define TEST_PHYSICAL_DISK

#include "absServices.h"
#include "../Dao/DaoPhysicalDisk.h"

class ServicePhysicalDisk {
private:
	DaoPhysicalDisk *dao;
	PhysicalDisk *disk;
	list<PhysicalDisk*> disks;
public:
	ServicePhysicalDisk() {
		dao = new DaoPhysicalDisk();
	}
	~ServicePhysicalDisk(){
		cout << "Objeto TestePhysicalDisk destruido" << endl;
	}
	bool testInit() {
		dao->loadData();
		if(dao->getPhysicalDisks().empty()) {
			cerr << "Falha ao coletar discos ou não existe disco neste sistema operacional!" << endl;
			return false;
		}
		disks = dao->getPhysicalDisks();
		return true;
	}
	list<PhysicalDisk*> getPhysicalDisks() {
		testInit();
		return disks;
	}
};

#endif
