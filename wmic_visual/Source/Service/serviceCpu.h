#include "../Dao/DaoCpu.h"
#include <string>
#include "absServices.h"

class ServiceCpu {
private:
    DaoCpu *dao;
    CPU *cpu;
    list<CPU*> cpus;	
public:
    ServiceCpu() {
        cout << "Constructor" << endl;		
        dao = new DaoCpu();
    }
    ~ServiceCpu() {
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
