#ifndef SERVICE_H
#define SERVICE_H

#include "win32.h"

class Service : private Win32Objs {
private:
	bool AcceptPause;
	bool AcceptStop;
	string Caption;
	uint32_t CheckPoint;
	string CreationClassName;
	bool DelayedAutoStart;
	string Description;
	bool DesktopInteract;
	string DisplayName;
	string ErrorControl;
	uint32_t ExitCode;
	string InstallDate;
	string Name;
	string PathName;
	uint32_t ProcessId;
	uint32_t ServiceSpecificExitCode;
	string ServiceType;
	bool Started;
	string StartMode;
	string StartName;
	string State;
	string Status;
	string SystemCreationClassName;
	string SystemName;
	uint32_t TagId;
	uint32_t WaitHint;
public:
	Service();
	bool getAcceptPause() const;
	void setAcceptPause(bool value);
	bool getAcceptStop() const;
	void setAcceptStop(bool value);
	string getCaption() const;
	void setCaption(const string& value);
	uint32_t getCheckPoint() const;
	void setCheckPoint(const uint32_t& value);
	string getCreationClassName() const;
	void setCreationClassName(const string& value);
	bool getDelayedAutoStart() const;
	void setDelayedAutoStart(bool value);
	string getDescription() const;
	void setDescription(const string& value);
	bool getDesktopInteract() const;
	void setDesktopInteract(bool value);
	string getDisplayName() const;
	void setDisplayName(const string& value);
	string getErrorControl() const;
	void setErrorControl(const string& value);
	uint32_t getExitCode() const;
	void setExitCode(const uint32_t& value);
	string getInstallDate() const;
	void setInstallDate(const string& value);
	string getName() const;
	void setName(const string& value);
	string getPathName() const;
	void setPathName(const string& value);
	uint32_t getProcessId() const;
	void setProcessId(const uint32_t& value);
	uint32_t getServiceSpecificExitCode() const;
	void setServiceSpecificExitCode(const uint32_t& value);
	string getServiceType() const;
	void setServiceType(const string& value);
	bool getStarted() const;
	void setStarted(bool value);
	string getStartMode() const;
	void setStartMode(const string& value);
	string getStartName() const;
	void setStartName(const string& value);
	string getState() const;
	void setState(const string& value);
	string getStatus() const;
	void setStatus(const string& value);
	string getSystemCreationClassName() const;
	void setSystemCreationClassName(const string& value);
	string getSystemName() const;
	void setSystemName(const string& value);
	uint32_t getTagId() const;
	void setTagId(const uint32_t& value);
	uint32_t getWaitHint() const;
	void setWaitHint(const uint32_t& value);
};

#endif // SERVICE_H
