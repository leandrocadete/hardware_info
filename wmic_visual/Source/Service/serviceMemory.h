#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H

#include "../Dao/DaoMemory.h"
#include <string>

class ServiceMemory {
private:
	DaoMemory *dao;
	PhysicalMemory *memory;
	list<PhysicalMemory*> memories;
	//ofstream file;
public:
	ServiceMemory() {
		dao = new DaoMemory();
	}
	~ServiceMemory() {
		cout << "Objeto TestMemory destruido!" << endl;
	}

	list<PhysicalMemory*> getMomories() {
		testInit();
		return memories;
	}

	bool testInit() {
		dao->loadData();
		if(dao->getMemory()->getPhysicalMemories().size() == 0) {
			cerr << "Falha ao coletar memorias neste sistema operacional!" << endl;
			return false;
		}
		memories = dao->getMemory()->getPhysicalMemories();
		return true;
	}
};

#endif
