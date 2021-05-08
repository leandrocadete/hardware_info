#ifndef TEST_PHYSICAL_DISK
#define TEST_PHYSICAL_DISK

#include "absttest.h"
#include "DaoPhysicalDisk.h"

class TestPhysicalDisk {
private:
	DaoPhysicalDisk *dao;
	PhysicalDisk *disk;
	list<PhysicalDisk*> disks;
public:
	TestPhysicalDisk() {
		dao = new DaoPhysicalDisk();
	}
	~TestPhysicalDisk(){
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
