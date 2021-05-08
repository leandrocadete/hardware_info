#include "DaoCpu.h"
#include <string>
#include "absttest.h"
#include "abstJson.h"

class TestCpu {
private:
    DaoCpu *dao;
    CPU *cpu;
    list<CPU*> cpus;	
	//ofstream file;
public:
    TestCpu() {
        cout << "Constructor" << endl;		
        dao = new DaoCpu();
    }
    ~TestCpu() {
        cout << "Objeto TestCpu destruido!" << endl;
    }
    list<CPU*> getCpus() {
        testInit();
        return cpus;
    }
    bool testInit() {        
        if(dao->loadCpus().size() == 0) {
            cerr << "Falha ao coletar CPUS!" << endl;
            return false;
        }		
        cpus = dao->getCpus();
        return true;
    }
    string test(bool &flag) {
		string str_result;
		//file.open("sysinfo.json", ios::app);
		//file << "\"CPU\":[" << endl;
        cout << "**********************************************************************************" << endl;
        cout << "************************\"TestCpu\" iniciado!**********************************" << endl;
        cerr << "************************\"TestCpu\" iniciado!**********************************" << endl;
        cerr << "**********************************************************************************" << endl;        
        flag = testInit() && flag;
        list<CPU*>::iterator iter = cpus.begin();
        list<CPU*>::iterator iterEnd = cpus.end();

        while(iter != iterEnd) {
            cpu = *iter;
            cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "{\n";
            str_result += deveriaRetornarArchiteture();
			str_result += ", ";
            flag = deveriaRetornarAssetTag() && flag;
            str_result +=  deveriaRetornarCaption();
			str_result += ", \n";
            flag = deveriaRetornarCharacteristics() && flag;
            flag = deveriaRetornarCreationClassName() && flag;
            str_result += deveriaRetornarCurrentClockSpeed();
			str_result += ", \n";;
            flag = deveriaRetornarCurrentVoltage() && flag;
            flag = deveriaRetornarDataWidth() && flag;
            flag = deveriaRetornarDescription() && flag;
            flag = deveriaRetornarDeviceID() && flag;
            flag = deveriaRetornarErrorCleared() && flag;
            flag = deveriaRetornarErrorDescription() && flag;
            str_result += deveriaRetornarExtClock();
			str_result += ", \n";;
            flag = deveriaRetornarFamily() && flag;
            str_result += deveriaRetornarL2CacheSize();
			str_result += ", \n";;
            flag = deveriaRetornarL2CacheSpeed() && flag;
            str_result += deveriaRetornarL3CacheSize();			
            flag = deveriaRetornarL3CacheSpeed() && flag;
            flag = deveriaRetornarLastErrorCode() && flag;
            flag = deveriaRetornarLevel() && flag;
			str_result += ", \n";
            str_result += deveriaRetornarLoadPercentage();
            //flag = deveriaRetornarManagerErrorCode() && flag;
			str_result += ", \n";
            str_result += deveriaRetornarManufacturer();
			str_result += ", \n";
            str_result += deveriaRetornarMaxClockSpeed();
			str_result += ", \n";
            str_result += deveriaRetornarName();
			str_result += ", \n";
            str_result += deveriaRetornarNumberOfCores();
            flag = deveriaRetornarNumberOfEnabledCore() && flag;
            flag = deveriaRetornarNumberOfLogicalProcessors() && flag;
            flag = deveriaRetornarOtherFamilyDescription() && flag;
            flag = deveriaRetornarPartNumber() && flag;
            flag = deveriaRetornarPNPDeviceID() && flag;
            flag = deveriaRetornarPowerManagementSupported() && flag;
            flag = deveriaRetornarProcessorID() && flag;
            flag = deveriaRetornarProcessorType() && flag;
            flag = deveriaRetornarRevision() && flag;
            flag = deveriaRetornarRole() && flag;
            flag = deveriaRetornarSecondLevelAddressTranslationExtensions() && flag;
            flag = deveriaRetornarSerialNumber() && flag;
            flag = deveriaRetornarSocketDesignation() && flag;
            flag = deveriaRetornarStatus() && flag;
            flag = deveriaRetornarStatusInfo() && flag;
            flag = deveriaRetornarStepping() && flag;
            flag = deveriaRetornarSystemCreationClassName() && flag;
            flag = deveriaRetornarSystemName() && flag;
            flag = deveriaRetornarThreadCount() && flag;
            flag = deveriaRetornarUniqueId() && flag;
            flag = deveriaRetornarVirtualizationFirmwareEnabled() && flag;
            flag = deveriaRetornarVMMonitorModeExtensions() && flag;
            flag = deveriaRetornarVoltageCaps() && flag;
            flag = deveriarRetornarAvailability() && flag;
            cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "}";
            iter++;
			if(iter != iterEnd) {
				str_result += ",\n";
			}
        }
        if(flag) cout << "Teste \"CPU\" OK!\n";
        else cerr << "Teste de \"CPU\" falhou!\n";
        cout << "**********************************************************************************" << endl;


		str_result += "]\n";
		//file.close();
        return str_result;
    }

    string deveriaRetornarArchiteture() {
        bool flag = true;
        if(cpu->getArchitecture() == 0) {
            cerr << "Não retornou Architecture!" << endl;
            flag = false;
        }
		return printString("Architecture", cpu->getArchitecture());
        //cout << "Architecture=" << cpu->getArchitecture() << endl;
		
        //return flag;
    }
    bool deveriaRetornarAssetTag() {
        if(cpu->getAssetTag().empty()) {
            cerr << "Não retornou AssetTag!" << endl;
            return false;
        }
        cout << "AssetTag=" << cpu->getAssetTag() << endl;
        return true;
    }
    bool deveriarRetornarAvailability() {
        if(cpu->getAvailability()== 0) {
            cerr << "Não retornou Availability!" << endl;
            return false;
        }
        cout << "Availability=" << cpu->getAvailability() << endl;
        return true;
    }
    string deveriaRetornarCaption() {
        if(cpu->getCaption().empty()) {
            cerr << "Não retornou Caption!" << endl;
            return false;
        }
		return printString("Caption", cpu->getCaption());
        //cout << "Caption=" << cpu->getCaption() << endl;
        //return true;
    }
    bool deveriaRetornarCharacteristics() {
        if(cpu->getCharacteristics()== 0) {
            cerr << "Não retornou Characteristics!" << endl;
            return false;
        }
        cout << "Characteristics=" << cpu->getCharacteristics() << endl;
        return true;
    }
//    bool deveriaRetornarManagerErrorCode() {
//        if(cpu->get < 0) {
//            cerr << "Não retornou ManagerErrorCode!" << endl;
//            return false;
//        }
//        cout << "Characteristics=" << cpu->getCharacteristics << endl;
//        return true;
//    }
    bool deveriaConfigManagerUserConfig() { cout << "ConfigManagerUserConfig=" << cpu->getConfigManagerUserConfig() << endl; return true; }
    bool deveriaRetornarCreationClassName() { return isEmpty("CreationClassName", cpu->getCreationClassName()); }
    string deveriaRetornarCurrentClockSpeed() { return printString("CurrentClockSpeed", cpu->getCurrentClockSpeed()); /*return notZero("CurrentClockSpeed", cpu->getCurrentClockSpeed());*/ }
    bool deveriaRetornarCurrentVoltage() { return notZero("CurrentVoltage", cpu->getCurrentVoltage()); }
    bool deveriaRetornarDataWidth() { return notZero("DataWidth", cpu->getDataWidth()); }
    bool deveriaRetornarDescription() { return isEmpty("Description", cpu->getDescription()); }
    bool deveriaRetornarDeviceID() { return isEmpty("DeviceID", cpu->getDeviceID()); }
    bool deveriaRetornarErrorCleared() { return showBool("ErrorCleared", cpu->getErrorCleared()); }
    bool deveriaRetornarErrorDescription() { return isEmpty("ErrorDescription", cpu->getErrorDescription()); }
	string deveriaRetornarExtClock () { return printString("ExtClock", cpu->getExtClock()); /*return notZero("ExtClock", cpu->getExtClock());*/ }
    bool deveriaRetornarFamily () { return  notZero("Family", cpu->getFamily()); }
    string deveriaRetornarL2CacheSize () { return printString("L2CacheSize", cpu->getL2CacheSize()); /*return notZero("L2CacheSize", cpu->getL2CacheSize());*/ }
    bool deveriaRetornarL2CacheSpeed () { return notZero("L2CacheSpeed", cpu->getL2CacheSpeed()); }
	string deveriaRetornarL3CacheSize () { return printString("L3CacheSize", cpu->getL3CacheSize()); /*return notZero("L3CacheSize", cpu->getL3CacheSize()); */}
    bool deveriaRetornarL3CacheSpeed () { return notZero("L3CacheSpeed", cpu->getL3CacheSpeed()); }
    bool deveriaRetornarLastErrorCode () { return notZero("LastErrorCode", cpu->getLastErrorCode()); }
    bool deveriaRetornarLevel () { return notZero("Level", cpu->getLevel()); }
    string deveriaRetornarLoadPercentage () { return printString("LoadPercentage", cpu->getLoadPercentage()); /*return notZero("LoadPercentage", cpu->getLoadPercentage());*/ }
    string deveriaRetornarManufacturer () { return printString("Manufacturer", cpu->getManufacturer());  /*return isEmpty("Manufacturer", cpu->getManufacturer());*/ }
    string deveriaRetornarMaxClockSpeed () { return printString("MaxClockSpeed", cpu->getMaxClockSpeed()); /*return notZero("MaxClockSpeed", cpu->getMaxClockSpeed());*/ }
    string deveriaRetornarName () { return printString("Name", cpu->getName()); /*return isEmpty("Name", cpu->getName());*/ }
	string deveriaRetornarNumberOfCores () { return printString("NumberOfCores", cpu->getNumberOfCores()); /*return notZero("NumberOfCores", cpu->getNumberOfCores());*/ }
    bool deveriaRetornarNumberOfEnabledCore () { return notZero("NumberOfEnabledCores", cpu->getNumberOfEnabledCore()); }
    bool deveriaRetornarNumberOfLogicalProcessors () { return notZero("NumberOfLogicalProcessors", cpu->getNumberOfLogicalProcessors()); }
    bool deveriaRetornarOtherFamilyDescription () { return isEmpty("OtherFamilyDescription", cpu->getOtherFamilyDescription()); }
    bool deveriaRetornarPartNumber () { return isEmpty("PartNumber", cpu->getPartNumber()); }
    bool deveriaRetornarPNPDeviceID () { return isEmpty("PNPDeviceID", cpu->getPNPDeviceID()); }
    bool deveriaRetornarPowerManagementSupported () { return showBool("PowerManagementSupported", cpu->getPowerManagementSupported()); }
    bool deveriaRetornarProcessorID () { return isEmpty("ProcessorID", cpu->getProcessorId()); }
    bool deveriaRetornarProcessorType () { return notZero("ProcessorType", cpu->getProcessorType()); }
    bool deveriaRetornarRevision () { return notZero("Revision", cpu->getRevision()); }
    bool deveriaRetornarRole () { return isEmpty("Role", cpu->getRole()); }
    bool deveriaRetornarSecondLevelAddressTranslationExtensions () { return showBool("LevelAddressTranslationExtensions", cpu->getSecondLevelAddressTranslationExtensions()); }
    bool deveriaRetornarSerialNumber () { return isEmpty("SerialNumber", cpu->getSerialNumber()); }
    bool deveriaRetornarSocketDesignation () { return isEmpty("SocketDesignation", cpu->getSocketDesignation()); }
    bool deveriaRetornarStatus () { return isEmpty("Status", cpu->getStatus()); }
    bool deveriaRetornarStatusInfo () { return notZero("StatusInfo", cpu->getStatusInfo()); }
    bool deveriaRetornarStepping () { return isEmpty("Stepping", cpu->getStepping()); }
    bool deveriaRetornarSystemCreationClassName () { return isEmpty("SystemCreationClassName", cpu->getSystemCreationClassName()); }
    bool deveriaRetornarSystemName () { return isEmpty("SystemName", cpu->getSystemName()); }
    bool deveriaRetornarThreadCount () { return notZero("ThreadCount", cpu->getThreadCount()); }
    bool deveriaRetornarUniqueId () { return isEmpty("UniqueID", cpu->getUniqueId()); }
    //bool deveriaRetornarUpgradeMethod () { return cpu->getU }
    //bool deveriaRetornarVersion () { return cpu->get }
    bool deveriaRetornarVirtualizationFirmwareEnabled () { return showBool("VirtualizationFirmwareEnabled", cpu->getVirtualizationFirmwareEnabled()); }
    bool deveriaRetornarVMMonitorModeExtensions () { return showBool("VMMonitorModeExtensions", cpu->getVMMonitorModeExtensions()); }
    bool deveriaRetornarVoltageCaps () { return notZero("VoltageCaps", cpu->getVoltageCaps()); }

};
