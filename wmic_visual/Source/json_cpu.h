#ifndef JSON_CPU_H
#define JSON_CPU_H 

#include "DaoCpu.h"
#include <string>
#include "abstJson.h"

class JsonCpu {
private:
    DaoCpu *dao;
    CPU *cpu;
    list<CPU*> cpus;
    ofstream *file;
public:
    JsonCpu(ofstream *f) {
        file = f;
        dao = new DaoCpu();        
    }
	JsonCpu(const JsonCpu &other);
    ~JsonCpu() {
        cout << "Objeto Json destruido!" << endl;
    }

    bool jsonInit() {
        if(dao->loadCpus().size() == 0) {
            cerr << "Falha ao coletar CPUS!" << endl;
            return false;
        }
        cpus = dao->getCpus();
        return true;
    }

    bool generateJson() {
        cout << "CPU";
        bool flag = true;
        flag = jsonInit();
        list<CPU*>::iterator iter = cpus.begin();
        list<CPU*>::iterator iterEnd = cpus.end();
        *file << "\"CPUS\": [" << endl;
        while(iter != iterEnd) {            
            cpu = *iter;
            cout << "----------------------------------------------------------------------------------" << endl;
            *file << "{";

            attArchiteture();
            attAssetTag();
            attCaption();
            attCharacteristics();
            attCreationClassName();
            attCurrentClockSpeed();
            attCurrentVoltage();
            attDataWidth();
            attDescription();
            attDeviceID();
            attErrorCleared();
            attErrorDescription();
            attExtClock();
            attFamily();
            attL2CacheSize();
            attL2CacheSpeed();
            attL3CacheSize();
            attL3CacheSpeed();
            attLastErrorCode();
            attLevel();
            attLoadPercentage();
            //attManagerErrorCode();
            attManufacturer();
            attMaxClockSpeed();
            attName();
            attNumberOfCores();
            attNumberOfEnabledCore();
            attNumberOfLogicalProcessors();
            attOtherFamilyDescription();
            attPartNumber();
            attPNPDeviceID();
            attPowerManagementSupported();
            attProcessorID();
            attProcessorType();
            attRevision();
            attRole();
            attSecondLevelAddressTranslationExtensions();
            attSerialNumber();
            attSocketDesignation();
            attStatus();
            attStatusInfo();
            attStepping();
            attSystemCreationClassName();
            attSystemName();
            attThreadCount();
            attUniqueId();
            attVirtualizationFirmwareEnabled();
            attVMMonitorModeExtensions();
            attVoltageCaps();
            attAvailability(); // remove comma

            iter++;
            if(iter == iterEnd) {
                *file << "}\n";
            } else {
                *file << "},\n";
            }
        }
        *file << "]" << endl;
        if(flag) cout << "Teste \"CPU\" OK!" << endl;
        else cerr << "Teste de \"CPU\" falhou!" << endl;
        cout << "**********************************************************************************" << endl;
		//delete dao;
		//delete cpu;		
        return flag;
    }
    void attArchiteture() { *file << printUint16("Achitecture", cpu->getArchitecture()); }
    void attAssetTag() { *file << printUint16("AssetTag", cpu->getArchitecture()); }
    void attAvailability() {
        string str = printUint16("Availability", cpu->getAvailability());
        str.pop_back();
        str.pop_back();
        *file << str;
    }
    void attCaption() { *file << printUint16("Caption", cpu->getArchitecture()); }
    void attCharacteristics() { *file << printUint32("Characteristics", cpu->getCharacteristics());  }
    void deveriaConfigManagerUserConfig() { *file << printBool("ConfigManagerUserConfig", cpu->getConfigManagerUserConfig()); }
    void attCreationClassName() { *file << printString("CreationClassName", cpu->getCreationClassName()); }
    void attCurrentClockSpeed() { *file << printUint32("CurrentClockSpeed", cpu->getCurrentClockSpeed()); }
    void attCurrentVoltage() { *file << printUint32("CurrentVoltage", cpu->getCurrentVoltage()); }
    void attDataWidth() { *file << printUint32("DataWidth", cpu->getDataWidth()); }
    void attDescription() { *file << printString("Description", cpu->getDescription()); }
    void attDeviceID() { *file << printString("DeviceID", cpu->getDeviceID()); }
    void attErrorCleared() { *file << printBool("ErrorCleared", cpu->getErrorCleared()); }
    void attErrorDescription() { *file << printString("ErrorDescription", cpu->getErrorDescription()); }
    void attExtClock () { *file << printUint32("ExtClock", cpu->getExtClock()); }
    void attFamily () { *file <<  printUint16("Family", cpu->getFamily()); }
    void attL2CacheSize () { *file << printUint32("L2CacheSize", cpu->getL2CacheSize()); }
    void attL2CacheSpeed () { *file << printUint32("L2CacheSpeed", cpu->getL2CacheSpeed()); }
    void attL3CacheSize () { *file << printUint32("L3CacheSize", cpu->getL3CacheSize()); }
    void attL3CacheSpeed () { *file << printUint32("L3CacheSpeed", cpu->getL3CacheSpeed()); }
    void attLastErrorCode () { *file << printUint32("LastErrorCode", cpu->getLastErrorCode()); }
    void attLevel () { *file << printUint16("Level", cpu->getLevel()); }
    void attLoadPercentage () { *file << printUint16("LoadPercentage", cpu->getLoadPercentage()); }
    void attManufacturer () { *file << printString("Manufacturer", cpu->getManufacturer()); }
    void attMaxClockSpeed () { *file << printUint32("MaxClockSpeed", cpu->getMaxClockSpeed()); }
    void attName () { *file << printString("", cpu->getName()); }
    void attNumberOfCores () { *file << printUint32("NumberOfCores", cpu->getNumberOfCores()); }
    void attNumberOfEnabledCore () { *file << printUint32("NumberOfEnabledCores", cpu->getNumberOfEnabledCore()); }
    void attNumberOfLogicalProcessors () { *file << printUint32("NumberOfLogicalProcessors", cpu->getNumberOfLogicalProcessors()); }
    void attOtherFamilyDescription () { *file << printString("OtherFamilyDescription", cpu->getOtherFamilyDescription()); }
    void attPartNumber () { *file << printString("PartNumber", cpu->getPartNumber()); }
    void attPNPDeviceID () { *file << printString("PNPDeviceID", cpu->getPNPDeviceID()); }
    void attPowerManagementSupported () { *file << printBool("PowerManagementSupported", cpu->getPowerManagementSupported()); }
    void attProcessorID () { *file << printString("ProcessorID", cpu->getProcessorId()); }
    void attProcessorType () { *file << printUint16("ProcessorType", cpu->getProcessorType()); }
    void attRevision () { *file << printUint16("Revision", cpu->getRevision()); }
    void attRole () { *file << printString("Role", cpu->getRole()); }
    void attSecondLevelAddressTranslationExtensions () { *file << printBool("LevelAddressTranslationExtensions", cpu->getSecondLevelAddressTranslationExtensions()); }
    void attSerialNumber () { *file << printString("SerialNumber", cpu->getSerialNumber()); }
    void attSocketDesignation () { *file << printString("SocketDesignation", cpu->getSocketDesignation()); }
    void attStatus () { *file << printString("Status", cpu->getStatus()); }
    void attStatusInfo () { *file << printUint16("StatusInfo", cpu->getStatusInfo()); }
    void attStepping () { *file << printString("Stepping", cpu->getStepping()); }
    void attSystemCreationClassName () { *file << printString("SystemCreationClassName", cpu->getSystemCreationClassName()); }
    void attSystemName () { *file << printString("SystemName", cpu->getSystemName()); }
    void attThreadCount () { *file << printUint32("ThreadCount", cpu->getThreadCount()); }
    void attUniqueId () { *file << printString("UniqueID", cpu->getUniqueId()); }
    //bool attUpgradeMethod () { *file << cpu->getU }
    //bool attVersion () { *file << cpu->get }
    void attVirtualizationFirmwareEnabled () { *file << printBool("VirtualizationFirmwareEnabled", cpu->getVirtualizationFirmwareEnabled()); }
    void attVMMonitorModeExtensions () { *file << printBool("VMMonitorModeExtensions", cpu->getVMMonitorModeExtensions()); }
    void attVoltageCaps () { *file << printUint32("VoltageCaps", cpu->getVoltageCaps()); }

};

#endif