#ifndef TESTSERVICE_H
#define TESTSERVICE_H

#include "abstJson.h"
#include <cstdio>
#include <cstring>
#include "daoservice.h"
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

    string test(bool &flag) {
		string str_result;
        //file.open("sysinfo.json", ios::app);		
		str_result += "\"Service\":";
		str_result += "[";

        //SetConsoleOutputCP(CP_UTF8);
        cout << "**********************************************************************************" << endl;
        cout << "**************************Teste de serviços iniciado*****************************" << endl;
        cerr << "**************************Teste de serviços iniciado*****************************" << endl;
        cout << "**********************************************************************************" << endl;        
        flag = testInit() && flag;
        list<Service*>::iterator iter = services.begin();
        list<Service*>::iterator iterEnd = services.end();

        while(iter != iterEnd) {
            service = *iter;
            cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "{";
            str_result += deveriaRetornarCaption();
            //file << ",";
            //flag = deveriaRetornarDescription() && flag;            
            //flag = deveriaRetornarDisplayName() && flag;
            flag = deveriaRetornarId() && flag;
            str_result += ",";
            str_result += deveriaRetornarName();
            str_result += ",";
            str_result += deveriaRetornarStartMode();
            str_result += ",";
            str_result += deveriaRetornarState();
            str_result += ",";
            str_result += deveriaRetornarStatus();
            cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "}";
            iter++;
			if(iter != iterEnd) {
				str_result += ",\n";
			}
        }
        if(flag) { cout << "Teste de serviços OK!" << endl; }
        else { cerr << "Teste de serviços falhou!" << endl; }
        cout << "**********************************************************************************" << endl;
        
		str_result += "],\n";
		//file.close();
		return str_result;
    }
    string deveriaRetornarCaption() {
        bool flag = true;
        if(service->getCaption().empty()) {
            cerr << "Não retornou Caption" << endl;
            flag = false;
        }
        return printString("Caption", service->getCaption());
        //cout << service->getCaption() << endl;            
        //return flag;
    }
    bool deveriaRetornarDisplayName() {
        bool flag = true;
        if(service->getDisplayName().empty()) {
            cerr << "Não retornou DisplayName" << endl;
            flag = false;
        }
        cout << service->getDisplayName() << endl;
        return flag;
    }
    string deveriaRetornarDescription() {
        bool flag = true;
        if(service->getDescription().empty()) {
            cerr << "Não retornou Description" << endl;
            flag = false;
        }
        return printString("Description", service->getDescription());
        //cout <<service->getDescription() << endl;
        //return flag;
    }
    string deveriaRetornarName() {
        bool flag = true;
        if(service->getName().empty()) {
            cerr << "Não retornou Name" << endl;
            flag = false;
        }
        return printString("Name", service->getName());
        //cout <<service->getName() << endl;
        //return flag;
    }
    bool deveriaRetornarId() {
        bool flag = true;
        if(service->getProcessId() == 0) {
            cerr << "Não retornou ProcessId" << endl;
            flag = false;
        }
        cout <<service->getProcessId() << endl;
        return flag;
    }
    string deveriaRetornarStatus() {
        bool flag = true;
        if(service->getStatus().empty()) {
            cerr << "Não retornou Status" << endl;
            flag = false;
        }
        return printString("Status", service->getStatus());
        //cout <<service->getStatus() << endl;
        //return flag;
    }
    string deveriaRetornarStartMode() {
        bool flag = true;
        if(service->getStartMode().empty()) {
            cerr << "Nao retornou StartMode" << endl;
        }
        return printString("StartMode", service->getStartMode());
        //cout <<service->getStartMode()<< endl;
        //return flag;
    }
    string deveriaRetornarState() {
        bool flag = true;
        if(service->getState().empty()) {
            cerr << "Não retornou State" << endl;
            flag = false;
        }
        return printString("State", service->getState());
        //cout <<service->getState() << endl;
        //return flag;
    }
};


#endif // TESTSERVICE_H
