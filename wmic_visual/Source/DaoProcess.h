#ifndef DAOPROCESS_H
#define DAOPROCESS_H

#include "win32.h"
#include "Process.h"
#include <stack>

class DaoProcess : private Win32Objs {
private:
	stack<Process*> processes;
	Process *process;
public:
	~DaoProcess(){}
	DaoProcess(){}
	stack<Process*> getProcesses() { return processes; }

	int loadData() {		
		char win32_class[] = "SELECT * FROM Win32_Process";
		HRESULT hres = NULL;
		IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
		if(pEnumerator == NULL) return 1;
		IWbemClassObject * pclsObj;
		ULONG uReturn = 0;

		while (pEnumerator) {
				hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
				if (uReturn == 0) break;
				VARIANT vtProp;
				string str;
				uint32_t uint32Value;
				uint16_t uint16Value;
				process = new Process();
				hres = getString(L"Name", &vtProp, pclsObj, str);
				process->setName(str);
				hres = getString(L"CreationDate", &vtProp, pclsObj, str);
				process->setCreationDate(str);
				hres = getString(L"CommandLine", &vtProp, pclsObj, str);								
				process->setCommandLine(str);
				hres = getString(L"Description", &vtProp, pclsObj, str);								
				process->setDescription(str);
				hres = getString(L"ExecutablePath", &vtProp, pclsObj, str);
				process->setExecutablePath(str);
				hres = getuInt32(L"priority", &vtProp, pclsObj, uint32Value); 
				process->setPriority(uint32Value);
				hres = getuInt16(L"ExecutionState", &vtProp, pclsObj, uint16Value); 
				process->setExecutionState(uint16Value);
				hres = getuInt32(L"ParentProcessId", &vtProp, pclsObj, uint32Value); 
				process->setParentProcessId(uint32Value);
				hres = getuInt32(L"ProcessId", &vtProp, pclsObj, uint32Value); 
				process->setProcessId(uint32Value);
				hres = getuInt32(L"SessionId", &vtProp, pclsObj, uint32Value); 
				process->setSessionId(uint32Value);
				hres = getuInt32(L"ThreadCount", &vtProp, pclsObj, uint32Value); 
				process->setThreadCount(uint32Value);
				processes.push(process);
			}
		gpSvc->Release();
		gpLoc->Release();
		CoUninitialize();
		return 0;
	}
};

#endif
