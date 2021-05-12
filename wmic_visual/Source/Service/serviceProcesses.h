#include "absServices.h"
#include "../Dao/DaoProcess.h"
#include <string>
class ServiceProcess /*: public AbsTest */{
private:
	stack<Process*> processes;
	DaoProcess *dao;
	Process *p;
public:
	stack<Process*> getProcess() {
		dao->loadData();
		return dao->getProcesses();
	}
	ServiceProcess() {
		dao = new DaoProcess();		
	}
	~ServiceProcess() {
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
