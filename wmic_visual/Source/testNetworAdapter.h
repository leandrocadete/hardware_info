#ifndef TEST_NETWORK_ADAPTER_H
#define TEST_NETWORK_ADAPTER_H

#include "abstJson.h"
#include "DaoNetworkAdapter.h"
#include <string>

class TestNetworkAdapter {
private:
	DaoNetworkAdapter *dao;
	NetworkAdapter *adapter;
	list<NetworkAdapter*> adapters;
	NetworkAdapterConfiguration configuration;
	//ofstream file;
public:
	TestNetworkAdapter () {
		dao = new DaoNetworkAdapter();
	}
	~TestNetworkAdapter () { 
		cout << "Objeto TesteNetworAdapter destruido!" << endl;
	}
	list<NetworkAdapter*> getNetworkAdapters() {
		testInit();
		return adapters;
	}
	bool testInit() {
		dao->loadData();
		if(dao->getNetworkadapters().size() == 0) {
			cerr << "Falha ao coletar interface de rede ou não existe interface de rede neste host" << endl;
			return false;
		}
		adapters = dao->getNetworkadapters();
		return true;
	}

	string test(bool &flag) {
		string str_result;
		//file.open("sysinfo.json", ios::app);
        str_result += "\"NetworkAdapter\":[\n";
		cout << "**********************************************************************************" << endl;
		cout << "******************Teste de Interface de rede iniciado!****************************" << endl;
		cerr << "******************Teste de Interface de rede iniciado!****************************" << endl;
		cout << "**********************************************************************************" << endl;
		flag = testInit() && flag;
		list<NetworkAdapter*>::iterator iter;
		list<NetworkAdapter*>::iterator iterEnd;
		iter = adapters.begin();
		iterEnd = adapters.end();
		while(iter != iterEnd) {
			
			adapter = *iter;
			configuration = adapter->getNetworkAdapterConfiguration();
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "{\n";
			str_result += deveriaRetornarCaption();
			str_result += ", \n";
			flag = deveriaRetornarDescription() && flag;
			flag = deveriaRetornarDeviceID() && flag;
			flag = deveriaRetornarIndex() && flag;
			str_result += deveriaRetornarMACAddress();
			str_result += ", \n";
			str_result += deveriaRetornarManufacturer();
			str_result += ", \n";
			str_result += deveriaRetornarName();
			str_result += ", \n";
			str_result += deveriaRetornarNetworkAddresses();
			iter++;
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "}";
			if(iter != iterEnd) {
				str_result += ",\n";
			}
		}
		if(flag) cout << "Teste \"NetworAdapter\" OK!" << endl;
		else cerr << "Teste de \"NetworAdapter\" falhou!" << endl;
		cout << "**********************************************************************************" << endl;

		str_result += "],\n";
		//file.close();
		return str_result;
	}
	string deveriaRetornarCaption () {
        bool flag = true;
		if(adapter->getCaption().empty()) {
			cerr << "Não retornou Caption!" << endl;
            flag = false;
		}
        return printString("Caption", adapter->getCaption());
		//cout << "Caption=" << adapter->getCaption() << endl;
        //return flag;
	}
	bool deveriaRetornarDescription () {
        bool flag = true;
		if(adapter->getDescription().empty()) {
			cerr << "Não retornou Description!" << endl;
            flag = false;
		}
		cout << "Description=" << adapter->getDescription() << endl;
        return flag;
	}
	bool deveriaRetornarDeviceID () {
        bool flag = true;
		if(adapter->getDeviceID().empty()) {
			cerr << "Não retornou DeviceID!" << endl;
            flag = false;
		}
		cout << "DeviceID=" << adapter->getDeviceID() << endl;
        return flag;
	}
	bool deveriaRetornarIndex () {
        bool flag = true;
		if(adapter->getIndex() < 0) {
			cerr << "Não retornou Index!" << endl;
            flag = false;
		}
		cout << "Index=" << adapter->getIndex() << endl;
        return flag;
	}
	string deveriaRetornarMACAddress () {
        bool flag = true;
		if(adapter->getMACAddress().empty()) {
			cerr << "Não retornou MACAddress!" << endl;
            flag = false;
		}
        return printString("MACAddress", adapter->getMACAddress());
		//cout << "MACAddress=" << adapter->getMACAddress() << endl;
        //return flag;
	}
	string deveriaRetornarManufacturer () {
        bool flag = true;
		if(adapter->getManufacturer().empty()) {
			cerr << "Não retornou Manufacturer!" << endl;
            flag = false;
		}
        return printString("Manufacturer", adapter->getManufacturer());
		//cout << "Manufacturer=" << adapter->getManufacturer() << endl;
        //return flag;
	}
	string deveriaRetornarName () {
        bool flag = true;
		if(adapter->getName().empty()) {
			cerr << "Não retornou Name!" << endl;
            flag = false;
		}
		return printString("Name", adapter->getName());
		//cout << "Name=" << adapter->getName() << endl;
        //return flag;
	}
    string deveriaRetornarNetworkAddresses () {
        bool flag = true;
		string str_temp;
		if(configuration.getIPAddress().empty()) {
			cerr << "Não retornou NetworkAddresses!" << endl;
            flag = false;
			return "\"Addresses\":[]";
		}      
        str_temp = "\"Addresses\":[";
        short size = configuration.getIPAddress().size();
        for (int i = 0; ; i++) {
			str_temp += "{";
            str_temp += printString("IP", configuration.getIPAddress()[i]);
			cout << "IP=" << configuration.getIPAddress()[i];
            //if(!size == i + 1) {
			str_temp += "}";
			if(i+1 == size) break;
			str_temp += ", \n";
            //}
        }
        str_temp += "]";
        return str_temp;
	}	

	bool deveriaRetornarDHCPLeaseExpires() {
        bool flag = true;
		if(configuration.getDHCPLeaseExpires().empty()) {
			cerr << "Não retornou DCHPLeaseExpires!" << endl;
            flag = false;
		}
		cout << "DCHPLeaseExpires=" << configuration.getDHCPLeaseExpires() << endl;
        return flag;
	}
	bool deveriaRetornarDHCPLeaseObtained() {
        bool flag = true;
		if(configuration.getDHCPLeaseObtained().empty()) {
			cerr << "Não retornou DHCPLeaseObtained!" << endl;
            flag = false;
		}
		cout << "DHCPLeaseObtained=" << configuration.getDHCPLeaseObtained() << endl;
        return flag;
	}
	string deveriaRetornarDHCPServer() {
        bool flag = true;
		if(!strlen(configuration.getDHCPServer())) {
			cerr << "Não retornou DHCPServer!" << endl;
            flag = false;
		}
        return printString("DHCPDHCPServer", configuration.getDHCPServer());
		//cout << "DHCPDHCPServer=" << configuration.getDHCPServer() << endl;
        //return flag;
	}
	string deveriaRetornarDNSHostName() {
        bool flag = true;
		if(configuration.getDNSHostName().empty()) {
			cerr << "Não retornou DNSHostName!" << endl;
            flag = false;
		}
        return printString("DNSHostName", configuration.getDNSHostName());
		//cout << "DNSHostName=" << configuration.getDNSHostName() << endl;
        //*return flag;
	}
	bool deveriaRetornarIndexC() {
        bool flag = true;
		if(configuration.getIndex()) {
			cerr << "Não retornou Index!" << endl;
            flag = false;
		}
		cout << "Index=" << configuration.getIndex() << endl;
        return flag;
	}
	string deveriaRetornarDomainDNSRegistrationEnabled() {
        bool flag = true;
		if(configuration.getDomainDNSRegistrationEnabled()) {
			cerr << "Não retornou DNSRegistrationEnabled!" << endl;
            flag = false;
		}
        return printString("DomainDNSRegistrationEnabled", configuration.getDomainDNSRegistrationEnabled());
		///cout << "DomainDNSRegistrationEnabled=" << configuration.getDomainDNSRegistrationEnabled() << endl;
        //return flag;
	}
	string deveriaRetornarDefaultIPGateway() {
        bool flag = true;
		string str_temp;
        if(configuration.getDefaultIPGateway().size()) {
            cerr << "Não retornou DefaultIPGateway!" << endl;
            flag = false;
        }
        short size = configuration.getDefaultIPGateway().size();
        str_temp = "\"DefaultIPGateway\":[";
        for(int i = 0; i < size; i++) {
            str_temp += printString("DefaultIPGateway", configuration.getDefaultIPGateway()[i]);
            cout << "DefaultIPGateway=" << configuration.getDefaultIPGateway()[i] << endl;
        }
        str_temp += "]\n";

        return str_temp;
	}
	bool deveriaRetornarDNSServerSearchOrder() {
        bool flag = true;
		if(configuration.getDNSServerSearchOrder().empty()) {
			cerr << "Não retornou DNSServerSearchOrder!" << endl;
            flag = false;
		}
		for(int i = 0; i < configuration.getDNSServerSearchOrder().size(); i++) {
			cout << "DNSServerSearchOrder=" << configuration.getDNSServerSearchOrder()[i] << endl;
		}
        return flag;
	}
	bool deveriaRetornarIPSubnet() {
        bool flag = true;
		if(configuration.getIPSubnet().empty()) {
			cerr << "Não retornou IPSubnet!" << endl;
            flag = false;
		}
		for(int i = 0; i < configuration.getIPSubnet().size(); i++) {
			cout << "IPSubnet=" << configuration.getIPSubnet()[i] << endl;
		}
        return flag;
	}

};

#endif
