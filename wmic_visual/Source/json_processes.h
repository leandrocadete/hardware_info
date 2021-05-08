#ifndef JSON_PROCESSES_H
#define JSON_PROCESSES_H
//#include "AbstractTest.h"0
#include "DaoProcess.h"
#include <string>
class JsonProcess /*: public AbsTest */{
private:
	stack<Process*> processes;
	DaoProcess *dao;
	Process *p;
public:
    JsonProcess() {
        //cout << "Construtor" << endl;
		dao = new DaoProcess();		
	}
    ~JsonProcess() {
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

	bool test() {
		cout << "**********************************************************************************" << endl;
		cout << "**************************Teste de processos iniciado*****************************" << endl;
		cerr << "**************************Teste de processos iniciado*****************************" << endl;
		cout << "**********************************************************************************" << endl;
		bool flag = true;
		flag = testInit() && flag;
		while(processes.size() > 0 ) {
			p = processes.top();
			cout << "----------------------------------------------------------------------------------" << endl;
			flag = deveriaRetornaCommandLine() && flag;
			flag = deveriaRetornaCreationDate() && flag;
			flag = deveriaRetornarDescription() && flag;
			flag = deveriaRetornarExecutablePath() && flag;
			flag = deveriaRetornarExecutionState() && flag;
			flag = deveriaRetornarName() && flag;
			flag = deveriaRetornarParentProcessId() && flag;
			flag = deveriaRetornarPriority() && flag;
			flag = deveriaRetornarProcessId() && flag;
			flag = deveriaRetornarSessionId() && flag;
			flag = deveriaRetornarThreadCount() && flag;
			cout << "----------------------------------------------------------------------------------" << endl;
			processes.pop();
		}
		if(flag) cout << "Teste de processos OK!" << endl;
		else cerr << "Teste de processos falhou!" << endl;
		cout << "**********************************************************************************" << endl;
		return flag;
	}

	bool deveriaRetornaCommandLine() {	
		if(p->getCommandLine().empty()) {
			cerr << "Não retornou Commandline" << endl;
			return false;
		}
		cout << "CommandLine=" << p->getCommandLine() << endl;		
		return true;
	}
	bool deveriaRetornaCreationDate() {
		if(p->getCreationDate().empty()) {
			cerr << "Não retornou CreationDate" << endl;
			return false;
		}
		cout << "CreationDate=" << p->getCreationDate() << endl;
		return true;
	}
	bool deveriaRetornarDescription() {
		if(p->getDescription().empty()) {
			cerr << "Não retornou Description" << endl;
			return false;
		}
		cout << "Description=" << p->getDescription() << endl;
		return true;
	}
	bool deveriaRetornarExecutablePath(){
		if(p->getCreationDate().empty()) {
			cerr << "Não retornou ExecutablePath" << endl;
			return false;
		}
		cout << "ExecutablePath=" << p->getExecutablePath() << endl;
		return true;
	}
	bool deveriaRetornarExecutionState(){
		if(p->getExecutionState() == 0) {
			cerr << "Não retornou ExecutionState: " << endl;
			return false;
		}
		cout << "ExecutionState=" <<  p->getExecutionState() << endl;
		return true;
	}
	bool deveriaRetornarName(){
		if(p->getName().empty()) {
			cerr << "Não retornou Name" << endl;
			return false;
		}
		cout << "Name=" << p->getName() << endl;
		return true;
	}
	bool deveriaRetornarParentProcessId(){
		if(p->getParentProcessId() == 0) {
			cerr << "Não retornou ParentProcessId: " << endl;
			return false;
		}
		cout << "ParentProcessId=" << p->getParentProcessId() << endl;
		return true;
	}
	bool deveriaRetornarPriority(){
		if(p->getParentProcessId() == 0) {
			cerr << "Não retornou Priority" << endl;
			return false;
		}
		cout << "Priority=" << p->getPriority() << endl;
		return true;
	}
	bool deveriaRetornarProcessId(){
		if(p->getProcessId() == 0) {			
			cerr << "Não retornou ProcessId" << endl;
			return false;
		}
		cout << "ProcessId=" << p->getParentProcessId() << endl;
		return true;
	}
	bool deveriaRetornarSessionId(){
		if(p->getSessionId() == 0) {			
			cerr << "Não retornou SessionId" << endl;
			return false;
		}
		cout << "SessionId=" << p->getSessionId() << endl;
		return true;
	}
	bool deveriaRetornarThreadCount(){
		if(p->getThreadCount() == 0) {
			return false;
			cerr << "Não retornou ThreadCount" << endl;			
		}
		cout << "ThreadCout=" << p->getThreadCount() << endl;
		return true;		
	}
};

#endif