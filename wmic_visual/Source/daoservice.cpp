#include "daoservice.h"


list<Service *> DaoService::getServices() const
{
    return services;
}

DaoService::DaoService() {
}
DaoService::~DaoService() {
}

list<Service*> DaoService::loadServices() {
    char win32_class[] = "SELECT * FROM Win32_Service";
    HRESULT hres = NULL;
    IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
    if(pEnumerator == NULL) return services;
    IWbemClassObject* pclsObj;
    unsigned long uReturn = 0;
    while (pEnumerator) {
        hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if(uReturn == 0) {
            break;
        }
        VARIANT vtProp;
        string str;
        uint32_t ui32;
        uint16_t ui16;
        uint64_t ui64;
        bool b = false;
        service = new Service();

        hres = getBoolean(L"AcceptPause", &vtProp, pclsObj, b);
        service->setAcceptPause(b);
        hres = getBoolean(L"AcceptSto", &vtProp, pclsObj, b);
        service->setAcceptStop(b);
        hres = getString(L"Caption", &vtProp, pclsObj, str);
        service->setCaption(str);
        service->setCheckPoint(ui32);
        hres = getString(L"CreationClassName", &vtProp, pclsObj, str);
        service->setCreationClassName(str);
        hres = getBoolean(L"DelayedAutoStart", &vtProp, pclsObj, b);
        service->setDelayedAutoStart(b);
        hres = getString(L"Description", &vtProp, pclsObj, str);
        service->setDescription(str);
        hres = getBoolean(L"DesktopInteract", &vtProp, pclsObj, b);
        service->setDesktopInteract(b);
        hres = getString(L"DisplayName", &vtProp, pclsObj, str);
        service->setDisplayName(str);
        hres = getString(L"ErrorControl", &vtProp, pclsObj, str);
        service->setErrorControl(str);
        hres = getuInt32(L"ExitCode", &vtProp, pclsObj, ui32);
        service->setExitCode(ui32);
        hres = getString(L"InstallDate", &vtProp, pclsObj, str);
        service->setInstallDate(str);
        hres = getString(L"Name", &vtProp, pclsObj, str);
        service->setName(str);
        hres = getString(L"PathName", &vtProp, pclsObj, str);
        service->setPathName(str);
        service->setProcessId(ui32);
        service->setServiceSpecificExitCode(ui32);
        hres = getString(L"ServiceType", &vtProp, pclsObj, str);
        service->setServiceType(str);
        hres = getBoolean(L"Started", &vtProp, pclsObj, b);
        service->setStarted(b);
        hres = getString(L"StartMode", &vtProp, pclsObj, str);
        service->setStartMode(str);
        hres = getString(L"StartName", &vtProp, pclsObj, str);
        service->setStartName(str);
        hres = getString(L"State", &vtProp, pclsObj, str);
        service->setState(str);
        hres = getString(L"Status", &vtProp, pclsObj, str);
        service->setStatus(str);
        hres = getString(L"SystemCreationClassName", &vtProp, pclsObj, str);
        service->setSystemCreationClassName(str);
        hres = getString(L"SystemName", &vtProp, pclsObj, str);
        service->setSystemName(str);
        service->setTagId(ui32);
        service->setWaitHint(ui32);

        services.push_back(service);
    }
    release();
    return services;

}
