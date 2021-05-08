#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H

#include "abstJson.h"
#include "DaoMemory.h"
#include <string>

class TestMemory {
private:
	DaoMemory *dao;
	PhysicalMemory *memory;
	list<PhysicalMemory*> memories;
	//ofstream file;
public:
	TestMemory() {
		dao = new DaoMemory();
	}
	~TestMemory() {
		cout << "Objeto TestMemory destruido!" << endl;
	}

	list<PhysicalMemory*> getMomories() {
		testInit();
		return memories;
	}

	bool testInit() {
		dao->loadData();
		if(dao->getMemory()->getPhysicalMemories().size() == 0) {
			cerr << "Falha ao coletar memorias neste sistema operacional!" << endl;
			return false;
		}
		memories = dao->getMemory()->getPhysicalMemories();
		return true;
	}

	string test(bool &flag) {
		string str_result;
		//file.open("sysinfo.json", ios::app);
        str_result += "\"Memory\":[\n";

		cout << "**********************************************************************************" << endl;
		cout << "************************\"testMemory\" iniciado!**********************************" << endl;
		cerr << "************************\"testMemory\" iniciado!**********************************" << endl;
		cout << "**********************************************************************************" << endl;
		flag = testInit() && flag;
		list<PhysicalMemory*>::iterator iter = memories.begin();
		list<PhysicalMemory*>::iterator iterEnd = memories.end();
		int i = 0;
		while(iter != iterEnd) {
			memory = *iter;
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "{\n";
			str_result += deveriaRetornarCaption();
            str_result += ", \n";
			str_result += deveriaRetornarBankLabel();
            str_result += ", \n";
			str_result += deveriaRetornarCapacity();
			flag = deveriaRetornarDataWidth() && flag;
			flag = deveriaRetornarDescription() && flag;
			flag = deveriaRetornarDeviceLocator() && flag;
			flag = deveriaRetornarFormFactor() && flag;
            str_result += ", \n";
			str_result += deveriaRetornarManufacturer();
            str_result += ", \n";
			flag = deveriaRetornarPositionInRow() && flag;
			flag = deveriaRetornarSerialNumber() && flag;
			str_result += deveriaRetornarSpeed();
			flag = deveriaRetornarTag() && flag;
			flag = deveriaRetornarTotalWidth() && flag;
			flag = deveriaRetornarTypeDetail() && flag;
			cout << "----------------------------------------------------------------------------------" << endl;
			str_result += "}\n";
			iter++;
			if(iter != iterEnd) {
				str_result += ",\n";
			}
		}
		if(flag) cout << "Teste \"Memory\" OK!" << endl;
		else cerr << "Teste de \"Memory\" falhou!" << endl;
		cout << "**********************************************************************************" << endl;

		str_result += "],\n";
		//file.close();
		return str_result;
	}

	string deveriaRetornarCaption() { 
        bool flag = true;
		if(memory->getAttributes() == 0) {
			cerr << "Não retornou Caption!" << endl;
            flag = false;
		}
        return printString("Attributes", memory->getCaption());
        //cout << "Attributes=" << memory->getCaption() << endl;
        //return flag;
	}
	string deveriaRetornarBankLabel() {
        bool flag = true;
		if(memory->getBankLabel().empty()) {
			cerr << "Não retornou BankLabel" << endl;
            flag = false;
		}
        return printString("BankLabel", memory->getBankLabel());
		//cout << "BankLabel=" << memory->getBankLabel() << endl;
        //return flag;
	}

	string deveriaRetornarCapacity() { 
        bool flag = true;
		if(memory->getCapacity() == 0) {
			cerr << "Não retornou Capacity" << endl;
            flag = false;
		}
        return printString("Capacity", memory->getCapacity());
		//cout << "Capacity=" << memory->getCapacity() << endl;
        //return flag;

	}
	bool deveriaRetornarDataWidth() { 
        bool flag = true;
		if(memory->getDataWidth() == 0) {
			cerr << "Não retornou DataWidth" << endl;
            flag = false;
		}
		cout << "DataWidth=" << memory->getDataWidth() << endl;
        return flag;
	}
	bool deveriaRetornarDescription() { 
        bool flag = true;
		if(memory->getDescription().empty()) {
			cerr << "Não retornou Description" << endl;
            flag = false;
		}
		cout << "Description=" << memory->getDescription() << endl;
        return flag;
	}
	bool deveriaRetornarDeviceLocator() { 
        bool flag = true;
		if(memory->getDeviceLocator().empty()) {
			cerr << "Não retornou DeviceLocator" << endl;
            flag = false;
		}
		cout << "DeviceLocator=" << memory->getDeviceLocator() << endl;
        return flag;
	}
	bool deveriaRetornarFormFactor() { 
        bool flag = true;
		if(memory->getFormFactor() == 0) {
			cerr << "Não retornou FormFactor" << endl;
            flag = false;
		}
		cout << "FormFactor=" << memory->getFormFactor() << endl;
        return flag;
	}
	string deveriaRetornarManufacturer() { 
        bool flag = true;
		if(memory->getManufacturer().empty()) {
			cerr << "Não retornou Manufacturer" << endl;
            flag = false;
		}
        return printString("Manufacturer", memory->getManufacturer());
		//cout << "Manufacturer=" << memory->getManufacturer() << endl;
        //return flag;
	}
	bool deveriaRetornarPositionInRow() {
        bool flag = true;
		if(memory->getPositionInRow() < 0) {
			cerr << "Não retornou PositionInRow" << endl;
            flag = false;
		}
		cout << "PositionInRow=" << memory->getPositionInRow() << endl;
        return flag;
	}
	bool deveriaRetornarSerialNumber() {
        bool flag = true;
		if(memory->getSerialNumber().empty()) {
			cerr << "Não retornou Serial Number" << endl;
            flag = false;
		}
		cout << "SerialNumber=" << memory->getSerialNumber() << endl;
        return flag;
	}
	string deveriaRetornarSpeed() {
        bool flag = true;
		if(memory->getSpeed() == 0) {
			cerr << "Não retornou Speed" << endl;
            flag = false;
		}
        return printString("Speed", memory->getSpeed());
		//cout << "Speed=" << memory->getSpeed() << endl;
        //return flag;
	}
	bool deveriaRetornarTag() {
        bool flag = true;
		if(memory->getTag().empty()) {
			cerr << "Não retornou Tag" << endl;
            flag = false;
		}
		cout << "Tag=" << memory->getTag() << endl;
        return flag;
	}
	bool deveriaRetornarTotalWidth() {
        bool flag = true;
		if(memory->getTotalWidth() == 0) {
			cerr << "Não retornou TotalWidth" << endl;
            flag = false;
		}
		cout << "TotalWidth=" << memory->getTotalWidth() << endl;
        return flag;
	}
	bool deveriaRetornarTypeDetail() {
        bool flag = true;
		if(memory->getTypeDetail() == 0) {
			cerr << "Não retornou TypeDetail" << endl;
            flag = false;
		}
		cout << "TypeDetail=" << memory->getTypeDetail() << endl;
        return flag;
	}
};

#endif
