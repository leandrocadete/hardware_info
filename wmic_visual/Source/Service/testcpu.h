#include "../Dao/DaoCpu.h"
#include <string>
#include "absttest.h"

class TestCpu {
private:
    DaoCpu *dao;
    CPU *cpu;
    list<CPU*> cpus;	
	//ofstream file;
public:
    TestCpu() {
        cout << "Constructor" << endl;		
        dao = new DaoCpu();
    }
    ~TestCpu() {
        cout << "Objeto TestCpu destruido!" << endl;
    }
    list<CPU*> getCpus() {
        testInit();
        return cpus;
    }
    bool testInit() {        
        if(dao->loadCpus().size() == 0) {
            cerr << "Falha ao coletar CPUS!" << endl;
            return false;
        }		
        cpus = dao->getCpus();
        return true;
    }
   
};
