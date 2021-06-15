#include "service.h"

bool Service::getAcceptPause() const { return AcceptPause; }
void Service::setAcceptPause(bool value) { AcceptPause = value; }
bool Service::getAcceptStop() const { return AcceptStop; }
void Service::setAcceptStop(bool value) { AcceptStop = value; }
string Service::getCaption() const { return Caption; }
void Service::setCaption(const string& value) { Caption = value; }
uint32_t Service::getCheckPoint() const { return CheckPoint; }
void Service::setCheckPoint(const uint32_t& value) { CheckPoint = value; }
string Service::getCreationClassName() const { return CreationClassName; }
void Service::setCreationClassName(const string& value) { CreationClassName = value; }
bool Service::getDelayedAutoStart() const { return DelayedAutoStart; }
void Service::setDelayedAutoStart(bool value) { DelayedAutoStart = value; }
string Service::getDescription() const { return Description; }
void Service::setDescription(const string& value) { Description = value; }
bool Service::getDesktopInteract() const { return DesktopInteract; }
void Service::setDesktopInteract(bool value) { DesktopInteract = value; }
string Service::getDisplayName() const { return DisplayName; }
void Service::setDisplayName(const string& value) { DisplayName = value; }
string Service::getErrorControl() const { return ErrorControl; }
void Service::setErrorControl(const string& value) { ErrorControl = value; }
uint32_t Service::getExitCode() const { return ExitCode; }
void Service::setExitCode(const uint32_t& value) { ExitCode = value; }
string Service::getInstallDate() const { return InstallDate; }
void Service::setInstallDate(const string& value) { InstallDate = value; }
string Service::getName() const { return Name; }
void Service::setName(const string& value) { Name = value; }
string Service::getPathName() const { return PathName; }
void Service::setPathName(const string& value) { PathName = value; }
uint32_t Service::getProcessId() const { return ProcessId; }
void Service::setProcessId(const uint32_t& value) { ProcessId = value; }
uint32_t Service::getServiceSpecificExitCode() const { return ServiceSpecificExitCode; }
void Service::setServiceSpecificExitCode(const uint32_t& value) { ServiceSpecificExitCode = value; }
string Service::getServiceType() const { return ServiceType; }
void Service::setServiceType(const string& value) { ServiceType = value; }
bool Service::getStarted() const { return Started; }
void Service::setStarted(bool value) { Started = value; }
string Service::getStartMode() const { return StartMode; }
void Service::setStartMode(const string& value) { StartMode = value; }
string Service::getStartName() const { return StartName; }
void Service::setStartName(const string& value) { StartName = value; }
string Service::getState() const { return State; }
void Service::setState(const string& value) { State = value; }
string Service::getStatus() const { return Status; }
void Service::setStatus(const string& value) { Status = value; }
string Service::getSystemCreationClassName() const { return SystemCreationClassName; }
void Service::setSystemCreationClassName(const string& value) { SystemCreationClassName = value; }
string Service::getSystemName() const { return SystemName; }
void Service::setSystemName(const string& value) { SystemName = value; }
uint32_t Service::getTagId() const { return TagId; }
void Service::setTagId(const uint32_t& value) { TagId = value; }
uint32_t Service::getWaitHint() const { return WaitHint; }
void Service::setWaitHint(const uint32_t& value) { WaitHint = value; }
Service::Service() {}
