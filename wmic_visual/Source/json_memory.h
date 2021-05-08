#ifndef JSON_MEMORY_H
#define JSON_MEMORY_H

#include "DaoMemory.h"
#include <string>
#include "abstJson.h"

class JsonMemory {
private:
	DaoMemory *dao;
	PhysicalMemory *memory;
	list<PhysicalMemory*> memories;
    ofstream *file;
public:
    JsonMemory(ofstream *f) {
        file = f;
		dao = new DaoMemory();
	}
	JsonMemory(const JsonMemory &other);

    ~JsonMemory() {
        cout << "Objeto TestMemory destruido!" << endl;
	}

    bool jsonInit() {
		dao->loadData();
		if(dao->getMemory()->getPhysicalMemories().empty()) {
			cerr << "Falha ao coletar memorias neste sistema operacional!" << endl;
			return false;
		}
		//memory = dao->getMemory()->getPhysicalMemories().front();
		memories = dao->getMemory()->getPhysicalMemories();
		return true;
	}

    bool gererateJson() {
        cout << "Memory" << endl;
        bool flag = true;
        flag = jsonInit();
        //cerr << "Size of Memories" << memories.size();
		list<PhysicalMemory*>::iterator iter = memories.begin();
		list<PhysicalMemory*>::iterator iterEnd = memories.end();
        *file << "\"Memories\": [" << endl;
		//int i = 0;
		while(iter != iterEnd) {
			memory = *iter;
			cout << "----------------------------------------------------------------------------------" << endl;
            *file << "{" << endl;

            attCaption();
            attBankLabel();
            attCapacity();
            attDataWidth();
            attDescription();
            attDeviceLocator();
            attFormFactor();
            attManufacturer();
            attPositionInRow();
            attSerialNumber();
            attSpeed();
            attTag();
            attTotalWidth();
            attTypeDetail();			
			iter++;
			cout << "----------------------------------------------------------------------------------" << endl;
            if(iter == iterEnd) {
                *file << "}\n";
            } else {
                *file << "},\n";
            }
		}
        *file << "]" << endl;
		if(flag) cout << "JSON \"Memory\" OK!" << endl;
		else cerr << "JSON de \"Memory\" falhou!" << endl;
		cout << "**********************************************************************************" << endl;
		return flag;
	}

    void attCaption() {
        *file << printUint32("Attributes",memory->getAttributes());
	}
    void attBankLabel() {
        *file << printString("BankLabel", memory->getBankLabel());
	}
    void attCapacity() {
        *file << printUint64("Capacity", memory->getCapacity());
	}
    void attDataWidth() {
        *file << printUint16("DataWidth", memory->getDataWidth());
	}
    void attDescription() {
        *file << printString("Description", memory->getDescription());
	}
    void attDeviceLocator() {
        *file << printString("DeviceLocator", memory->getDeviceLocator());
	}
    void attFormFactor() {
        *file << printUint16("FormFactor", memory->getFormFactor());
	}
    void attManufacturer() {
        *file << printString("Manufacturer", memory->getManufacturer());
	}
    void attPositionInRow() {
        *file << printUint32("PositionInRow", memory->getPositionInRow());
	}
    void attSerialNumber() {
        *file << printString("SerialNumber", memory->getSerialNumber());
	}
    void attSpeed() {
        *file << printUint32("Speed", memory->getSpeed());
	}
    void attTag() {
        *file << printString("Tag", memory->getTag());
	}
    void attTotalWidth() {
        *file << printUint16("TotalWidth", memory->getTotalWidth());
	}
    void attTypeDetail() {
        *file << printUint16("TypeDetail", memory->getTypeDetail());
	}
};

#endif