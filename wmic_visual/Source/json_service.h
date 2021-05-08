#ifndef TESTSERVICE_H
#define TESTSERVICE_H

#include "daoservice.h"
#include <string>
#include <list>

class JsonService {
private:
    list<Service*> services;
    DaoService *dao;
    Service *service;
public:
    JsonService() { }
    ~JsonService() {
        cout << "Objeto TestService destruído" << endl;
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

    bool test() {
        cout << "**********************************************************************************" << endl;
        cout << "**************************Teste de serviços iniciado*****************************" << endl;
        cerr << "**************************Teste de serviços iniciado*****************************" << endl;
        cout << "**********************************************************************************" << endl;
        bool flag = true;
        flag = testInit() && flag;

        list<Service*>::iterator iter = services.begin();
        list<Service*>::iterator iterEnd = services.end();

        while(iter != iterEnd) {
            service = *iter;
            cout << "----------------------------------------------------------------------------------" << endl;
            flag = deveriaRetornarCaption() && flag;
            flag = deveriaRetornarDescription() && flag;
            flag = deveriaRetornarDisplayName() && flag;
            flag = deveriaRetornarId() && flag;
            flag = deveriaRetornarName() && flag;
            flag = deveriaRetornarStartMode() && flag;
            flag = deveriaRetornarState() && flag;
            flag = deveriaRetornarStatus() && flag;
            cout << "----------------------------------------------------------------------------------" << endl;
            iter++;
        }
        if(flag) { cout << "Teste de serviços OK!" << endl; }
        else { cerr << "Teste de serviços falhou!" << endl; }
        cout << "**********************************************************************************" << endl;
        return flag;
    }
    bool deveriaRetornarCaption() {
        if(service->getCaption().empty()) {
            cerr << "Não retornou Caption" << endl;
            return false;
        }
        cout << service->getCaption() << endl;            
        return true;
    }
    bool deveriaRetornarDisplayName() {
        if(service->getDisplayName().empty()) {
            cerr << "Não retornou DisplayName" << endl;
            return false;
        }
        cout <<service->getDisplayName() << endl;
        return true;
    }
    bool deveriaRetornarDescription() {
        if(service->getDescription().empty()) {
            cerr << "Não retornou Description" << endl;
            return false;
        }
        cout <<service->getDescription() << endl;
        return true;
    }
    bool deveriaRetornarName() {
        if(service->getName().empty()) {
            cerr << "Não retornou Name" << endl;
            return false;
        }
        cout <<service->getName() << endl;
        return true;
    }
    bool deveriaRetornarId() {
        if(service->getProcessId() == 0) {
            cerr << "Não retornou ProcessId" << endl;
            return false;
        }
        cout <<service->getProcessId() << endl;
        return true;
    }
    bool deveriaRetornarStatus() {
        if(service->getStatus().empty()) {
            cerr << "Não retornou Status" << endl;
            return false;
        }
        cout <<service->getStatus() << endl;
        return true;
    }
    bool deveriaRetornarStartMode() {
        cout <<service->getStartMode()<< endl;
        return true;
    }
    bool deveriaRetornarState() {
        if(service->getState().empty()) {
            cerr << "Não retornou State" << endl;
            return false;
        }
        cout <<service->getState() << endl;
        return true;
    }
};


#endif // TESTSERVICE_H
