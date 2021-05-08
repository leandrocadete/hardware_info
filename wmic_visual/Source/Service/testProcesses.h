#include "absttest.h"
#include "../Dao/DaoProcess.h"
#include <string>
class TestProcess /*: public AbsTest */{
private:
	stack<Process*> processes;
	DaoProcess *dao;
	Process *p;
public:
	stack<Process*> getProcess() {
		dao->loadData();
		return dao->getProcesses();
	}
	TestProcess() {
		dao = new DaoProcess();		
	}
	~TestProcess() {
		cout << "Objeto TestProcess destruido" << endl;
	}
	bool testInit() {
		dao->loadData();
		if(dao->getProcesses().empty()) {
			cerr << "Falha ao coletar processos!" << endl;
			return false;
		}
		processes = dao->getProcesses();
		return true;
	}
};
