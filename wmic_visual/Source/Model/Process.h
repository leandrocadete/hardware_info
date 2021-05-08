#ifndef PROCESS_H
#define PROCESS_H

#include "win32.h"

class Process : public Win32_Wmi {
	string CommandLine;
	string CreationDate;
	string Description;
	string ExecutablePath;
	uint16_t ExecutionState;
	string Name;
	uint32_t ParentProcessId;
	uint32_t Priority;
	uint32_t ProcessId;
	uint32_t SessionId;
	//string Status;
	uint32_t ThreadCount;
public:
    Process(){}
    ~Process(){}
	void setCommandLine(string str) { CommandLine=str; }
	void setCreationDate(string str) { CreationDate=str; }
	void setDescription(string str) { Description=str; }
	void setExecutablePath(string str) { ExecutablePath=str; }
	void setExecutionState(uint16_t n) { ExecutionState=n; }
	void setName(string str) { Name=str; }
	void setParentProcessId(uint32_t n) { ParentProcessId=n; }
	void setPriority(uint32_t n) { Priority=n; }
	void setProcessId(uint32_t n) { ProcessId=n; }
	void setSessionId(uint32_t n) { SessionId = n; }
	//void setStatus(string str) { Status = str; };
	void setThreadCount(uint32_t n) { ThreadCount = n; }

	string getCommandLine() { return CommandLine; }
	string getCreationDate() { return CreationDate; }
	string getDescription() { return Description; }
	string getExecutablePath() {return ExecutablePath; }
	uint16_t getExecutionState() { return ExecutionState; }
	string getName() { return Name; }
	uint32_t getParentProcessId() { return ParentProcessId; }
	uint32_t getPriority() { return Priority; }	
	uint32_t getProcessId() { return ProcessId; }
	uint32_t getSessionId() { return SessionId; } 
	//string getStatus() { return Status; }
	uint32_t getThreadCount() { return ThreadCount; }
};

#endif
