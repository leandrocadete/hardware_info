#include "absttest.h"
#include "abstJson.h"
#include "DaoProcess.h"
#include <string>
class TestProcess /*: public AbsTest */{
private:
	stack<Process*> processes;
	DaoProcess *dao;
	Process *p;
	//ofstream file;
public:
	stack<Process*> getProcess() {
		dao->loadData();
		return dao->getProcesses();
	}


	TestProcess() {
        //cout << "Construtor" << endl;
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

	string test(bool &flag) {
		string str_result;
		//str_result += "something";
		//str_result += "123456789";
		///file.open("sysinfo.json", ios::app);
		str_result += "\"Processes\":";
		str_result += "[";
		

		cout << "**********************************************************************************" << endl;
		cout << "**************************Teste de processos iniciado*****************************" << endl;
		cerr << "**************************Teste de processos iniciado*****************************" << endl;
		cout << "**********************************************************************************" << endl;
		flag = testInit() && flag;
		while(processes.size() > 0 ) {
			p = processes.top();
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "{";
			flag = deveriaRetornaCommandLine() && flag;
			flag = deveriaRetornaCreationDate() && flag;
			flag = deveriaRetornarDescription() && flag;
			flag = deveriaRetornarExecutablePath() && flag;
			flag = deveriaRetornarExecutionState() && flag;
			//flag = deveriaRetornarName() && flag;
			str_result += deveriaRetornarName();
            str_result += ", ";
			flag = deveriaRetornarParentProcessId() && flag;
			flag = deveriaRetornarPriority() && flag;
			//flag = deveriaRetornarProcessId() && flag;
			str_result += deveriaRetornarProcessId();
			flag = deveriaRetornarSessionId() && flag;
			flag = deveriaRetornarThreadCount() && flag;
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "}";
			processes.pop();
			if(!processes.empty()) {
				str_result += ",\n";
			}
		}
		if(flag) cout << "Teste de processos OK!" << endl;
		else cerr << "Teste de processos falhou!" << endl;
		cout << "**********************************************************************************" << endl;

		str_result += "],\n";
		//file.close();
		//file.clear();
		return str_result;
	}

	bool deveriaRetornaCommandLine() {	
        bool flag = true;
		if(p->getCommandLine().empty()) {
			cerr << "Não retornou Commandline" << endl;
            flag = false;
		}
		cout << "CommandLine=" << p->getCommandLine() << endl;		
        return flag;
	}
	bool deveriaRetornaCreationDate() {
        bool flag = true;
		if(p->getCreationDate().empty()) {
			cerr << "Não retornou CreationDate" << endl;
            flag = false;
		}
		cout << "CreationDate=" << p->getCreationDate() << endl;
        return flag;
	}
	bool deveriaRetornarDescription() {
        bool flag = true;
		if(p->getDescription().empty()) {
			cerr << "Não retornou Description" << endl;
            flag = false;
		}
		cout << "Description=" << p->getDescription() << endl;
        return flag;
	}
	bool deveriaRetornarExecutablePath(){
        bool flag = true;
		if(p->getCreationDate().empty()) {
			cerr << "Não retornou ExecutablePath" << endl;
            flag = false;
		}
		cout << "ExecutablePath=" << p->getExecutablePath() << endl;
        return flag;
	}
	bool deveriaRetornarExecutionState(){
        bool flag = true;
		if(p->getExecutionState() == 0) {
			cerr << "Não retornou ExecutionState: " << endl;
            flag = false;
		}
		cout << "ExecutionState=" <<  p->getExecutionState() << endl;
        return flag;
	}
	string deveriaRetornarName(){
        bool flag = true;
		if(p->getName().empty()) {
			cerr << "Não retornou Name" << endl;
            flag = false;
		}
		return printString("Name", p->getName());
		//cout << "Name=" << p->getName() << endl;
        //return flag;
	}
	bool deveriaRetornarParentProcessId(){
        bool flag = true;
		if(p->getParentProcessId() == 0) {
			cerr << "Não retornou ParentProcessId: " << endl;
            flag = false;
		}
		cout << "ParentProcessId=" << p->getParentProcessId() << endl;
        return flag;
	}
	bool deveriaRetornarPriority(){
        bool flag = true;
		if(p->getParentProcessId() == 0) {
			cerr << "Não retornou Priority" << endl;
            flag = false;
		}
		cout << "Priority=" << p->getPriority() << endl;
        return flag;
	}
	string deveriaRetornarProcessId(){
        bool flag = true;
		if(p->getProcessId() == 0) {			
			cerr << "Não retornou ProcessId" << endl;
            flag = false;
		}
		return printString("ProcessId", p->getProcessId());
		//cout << "ProcessId=" << p->getParentProcessId() << endl;
        //return flag;
	}
	bool deveriaRetornarSessionId(){
        bool flag = true;
		if(p->getSessionId() == 0) {			
			cerr << "Não retornou SessionId" << endl;
            flag = false;
		}
		cout << "SessionId=" << p->getSessionId() << endl;
        return flag;
	}
	bool deveriaRetornarThreadCount(){
        bool flag = true;
		if(p->getThreadCount() == 0) {
            flag = false;
			cerr << "Não retornou ThreadCount" << endl;			
		}
		cout << "ThreadCout=" << p->getThreadCount() << endl;
        return flag;
	}
};
