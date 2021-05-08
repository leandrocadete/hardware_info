#include "DaoCpu.h"

DaoCpu::DaoCpu(){}

list<CPU*> DaoCpu::loadCpus() {
    char win32_class[] = "SELECT * FROM Win32_Processor";
    HRESULT hres = NULL;
    IEnumWbemClassObject* pEnumerator = init(win32_class, hres);
    if(pEnumerator == NULL) { return cpus; }
    IWbemClassObject* pclsObj;
    unsigned long uReturn = 0;
    while (pEnumerator) {
        hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if (uReturn == 0) break;
        VARIANT vtProp;
        string str;
        uint32_t u32;
        uint16_t u16;
        uint64_t u64;
        bool b;       


        cpu = new CPU();
        getuInt16(L"Architecture", &vtProp, pclsObj, u16);        
        cpu->setArchitecture(u16);        
        getString(L"Caption", &vtProp, pclsObj, str);
        cpu->setCaption(str);        
        getuInt32(L"Characteristics", &vtProp, pclsObj, u32);
        cpu->setCharacteristics(u32);
        getuInt32(L"ConfigManagerErrorCode", &vtProp, pclsObj, u32);
        cpu->setConfigManagerErrorCode(u32);



        getBoolean(L"ConfigManageruserConfig", &vtProp, pclsObj, b);
        cpu->setConfigManageruserConfig(b);
        getuInt16(L"CpuStatus", &vtProp, pclsObj, u16);
        cpu->setCpuStatus(10);
        getString(L"CreationClassName", &vtProp, pclsObj, str);
        cpu->setCreationClassName(str);
        getuInt32(L"CurrentClockSpeed", &vtProp, pclsObj, u32);
        cpu->setCurrentClockSpeed(u32);
        getuInt16(L"CurrentVoltage", &vtProp, pclsObj, u16);
        cpu->setCurrentVoltage(u16);
        getuInt16(L"DataWidth", &vtProp, pclsObj, u16);
        cpu->setDataWidth(u16);
        getString(L"Description", &vtProp, pclsObj, str);
        cpu->setDescription(str);
        getString(L"DeviceID", &vtProp, pclsObj, str);
        cpu->setDeviceID(str);
        getBoolean(L"ErrorCleared", &vtProp, pclsObj, b);
        cpu->setErrorCleared(b);
        getString(L"ErrorDescription", &vtProp, pclsObj, str);
        cpu->setErrorDescription(str);
        getuInt32(L"ExtClock", &vtProp, pclsObj, u32);
        cpu->setExtClock(u32);
        getuInt16(L"Family", &vtProp, pclsObj, u16);
        cpu->setFamily(u16);
        getuInt32(L"L2CacheSize", &vtProp, pclsObj, u32);
        cpu->setL2CacheSize(u32);
        getuInt32(L"L2CacheSpeed", &vtProp, pclsObj, u32);
        cpu->setL2CacheSpeed(u32);
        getuInt32(L"L3CacheSize", &vtProp, pclsObj, u32);
        cpu->setL3CacheSize(u32);
        getuInt32(L"L3ChacheSpeed", &vtProp, pclsObj, u32);
        cpu->setL3CacheSpeed(u32);
        getuInt32(L"LastErrorCode", &vtProp, pclsObj, u32);
        cpu->setLastErrorCode(u32);
        getuInt16(L"Level", &vtProp, pclsObj, u16);
        cpu->setLevel(u16);
        getuInt16(L"LoadPercentage", &vtProp, pclsObj, u16);
        cpu->setLoadPercentage(u16);
        getString(L"Manufacturer", &vtProp, pclsObj, str);
        cpu->setManufacturer(str);
        getuInt32(L"MaxClockSpeed", &vtProp, pclsObj, u32);
        cpu->setMaxClockSpeed(u32);
        getString(L"Name", &vtProp, pclsObj, str);
        cpu->setName(str);


        getuInt32(L"NumberOfCores", &vtProp, pclsObj, u32);
        cpu->setNumberOfCores(u32);
        getuInt32(L"NumberOfEnabledCore", &vtProp, pclsObj, u32);
        cpu->setNumberOfEnabledCore(u32);
        getuInt32(L"NumberOfLogicalProcessors", &vtProp, pclsObj, u32);
        cpu->setNumberOfLogicalProcessors(u32);
        getString(L"OtherFamilyDescription", &vtProp, pclsObj, str);
        cpu->setOtherFamilyDescription(str);
        getString(L"PartNumber", &vtProp, pclsObj, str);
        cpu->setPartNumber(str);
        getString(L"PNPDeviceID", &vtProp, pclsObj, str);
        cpu->setPNPDeviceID(str);
        vector<uint16_t> vpmc;
        //vpmc = getVectorChars();

        //cpu->setPowerManagementCapabilities(vpmc);
        getBoolean(L"PowerManagementSupported", &vtProp, pclsObj, b);
        cpu->setPowerManagementSupported(b);
        getString(L"ProcessorID", &vtProp, pclsObj, str);
        cpu->setProcessorId(str);
        getuInt16(L"ProcessorType", &vtProp, pclsObj, u16);
        cpu->setProcessorType(u16);
        getuInt16(L"Revision", &vtProp, pclsObj, u16);
        cpu->setRevision(u16);
        getString(L"Role", &vtProp, pclsObj, str);
        cpu->setRole(str);
        getBoolean(L"SecondLevelAddressTranslationExtensions", &vtProp, pclsObj, b);
        cpu->setSecondLevelAddressTranslationExtensions(b);
        getString(L"SerialNumber", &vtProp, pclsObj, str);
        cpu->setSerialNumber(str);
        getString(L"SocketDesignation", &vtProp, pclsObj, str);
        cpu->setSocketDesignation(str);


        getString(L"Status", &vtProp, pclsObj, str);
        cpu->setStatus(str);
        getuInt16(L"StatusInfo", &vtProp, pclsObj, u16);
        cpu->setStatusInfo(u16);
        getString(L"Stepping", &vtProp, pclsObj, str);
        cpu->setStepping(str);
        getString(L"SystemCreationClassName", &vtProp, pclsObj, str);
        cpu->setSystemCreationClassName(str);
        getString(L"Caption", &vtProp, pclsObj, str);
        cpu->setSystemName(str);

        getuInt32(L"ThreadCount", &vtProp, pclsObj, u32);
        cpu->setThreadCount(u32);
        getString(L"UniqueId", &vtProp, pclsObj, str);
        cpu->setUniqueId(str);
        getBoolean(L"VirtualizationFirmwareEnabled", &vtProp, pclsObj, b);
        cpu->setVirtualizationFirmwareEnabled(b);

        getBoolean(L"VMMonitorModeExtensions", &vtProp, pclsObj, b);
        cpu->setVMMonitorModeExtensions(b);

        getuInt32(L"VoltageCaps", &vtProp, pclsObj, u32);
        cpu->setVoltageCaps(u32);

        cpus.push_back(cpu);
    }
    return cpus;
}
