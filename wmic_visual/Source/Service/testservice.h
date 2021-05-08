#ifndef TESTSERVICE_H
#define TESTSERVICE_H

#include <cstdio>
#include <cstring>
#include "../Dao/daoservice.h"
#include <string>
#include <list>

class TestService {
private:
    list<Service*> services;
    DaoService *dao;
    Service *service;
	//ofstream file;
public:
    TestService() { }
    ~TestService() {
        cout << "Objeto TestService destruído" << endl;
    }

    list<Service*> getServices() {
        testInit();
        return services;
    }

    bool testInit() {        
        dao = new DaoService();
        dao->loadServices();
        if(dao->getServices().empty()) {
            cerr << "Falha ao coletar serviços!" << endl;
            return false;
        }
        services = dao->getServices();
        return true;
    }
};

#endif // TESTSERVICE_H
