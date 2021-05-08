//#include "AbstractTest.h"
#ifndef TEST_PHYSICAL_DISK
#define TEST_PHYSICAL_DISK

#include "absttest.h"
#include "DaoPhysicalDisk.h"

class TestPhysicalDisk /*: public AbsTest*/ {
private:
	DaoPhysicalDisk *dao;
	PhysicalDisk *disk;
	list<PhysicalDisk*> disks;
	//ofstream file;
public:
	TestPhysicalDisk() {
		dao = new DaoPhysicalDisk();
	}
	~TestPhysicalDisk(){
		cout << "Objeto TestePhysicalDisk destruido" << endl;
	}
	bool testInit() {
		dao->loadData();
		if(dao->getPhysicalDisks().empty()) {
			cerr << "Falha ao coletar discos ou não existe disco neste sistema operacional!" << endl;
			return false;
		}

		

		disks = dao->getPhysicalDisks();
		return true;
	}
	list<PhysicalDisk*> getPhysicalDisks() {
		testInit();
		return disks;
	}

	string test (bool &flag) {
		string str_result;
		//file.open("sysinfo.json", ios::app);
        str_result += "\t\"PhysicalDisk\":";
		str_result += "[\n";
		cout << "**********************************************************************************" << endl;
		cout << "************Teste de unidade físicas/armazenamento (Discos) iniciado!*************" << endl;
		cerr << "************Teste de unidade físicas/armazenamento (Discos) iniciado!*************" << endl;
		cout << "**********************************************************************************" << endl;
		flag = testInit() && flag;
		list<PhysicalDisk*>::iterator iter = disks.begin();
		list<PhysicalDisk*>::iterator iterEnd = disks.end();
        SetConsoleOutputCP(CP_UTF8);
		while(iter != iterEnd) {
			disk = *iter;
			cout << "----------------------------------------------------------------------------------" << endl;
            str_result += "\t\t{";
			str_result += deveriaRetornarCaption();
            str_result += ", \n";
			str_result += deveriaRetornarDescription();
            str_result += ", \n";
			flag = deveriaRetornarDeviceID() && flag;
			flag = deveriaRetornarIndex() && flag;
			flag = deveriaRetornarManufacturer() && flag;
			flag = deveriaRetornarModel() && flag;
			str_result += deveriaRetornarName();
            str_result += ", \n";
			str_result += deveriaRetornarPartitions();
			flag = deveriaRetornarPNPDeviceID() && flag;
			flag = deveriaRetornarSectorsPerTrack() && flag;
			flag = deveriaRetornarSerialNumber() && flag;
			flag = deveriaRetornarSize() && flag;
			flag = deveriaRetornarStatus() && flag;
			flag = deveriaRetornarStatusInfo() && flag;
			flag = deveriaRetornarTotalCylinders() && flag;
			flag = deveriaRetornarTotalHeads() && flag;
			flag = deveriaRetornarTotalSectors() && flag;
			flag = deveriaRetornarTotalTracks() && flag;
			flag = deveriaRetornarTracksPerCylinder() && flag;			
			cout << "----------------------------------------------------------------------------------" << endl;
            str_result += "}\n";

			iter++;
			if(iter != iterEnd) {
				str_result += ",\n";
			}

		}
		
		if(flag) cout << "Teste de PhysicalDisks OK!" << endl;
		else cerr << "Teste de PhysicalDisks falhou!" << endl;
		cout << "**********************************************************************************" << endl;

        str_result += "],\n";
		//file.close();
		return str_result;
	}

    string deveriaRetornarCaption() {
        bool flag = true;
		if(disk->getCaption().empty()) {			
			cerr << "Não retornou Caption" << endl;
            flag = false;
		}
		return printString("Caption", disk->getCaption());
		//cout << "Caption=" << disk->getCaption() << endl;
        //return flag;
	}
	string deveriaRetornarDescription() {
        bool flag = true;
		if(disk->getDescription().empty()) {
			cerr << "Não retornou Description" << endl;
            flag = false;
		}
		return printString("Description", disk->getDescription());
		//cout << "Description=" << disk->getDescription() << endl;
        //return flag;
	}
	bool deveriaRetornarDeviceID() {
        bool flag = true;
		if(disk->getDeviceID().empty()) {
			cerr << "Não retornou  DeviceID" << endl;
            flag = false;
		}
		cout << "DeviceID=" << disk->getDeviceID() << endl;
        return flag;
	}
	bool deveriaRetornarIndex() {
        bool flag = true;
		if(disk->getIndex() < 0) {
			cerr << "Não retornou  Index" << endl;
            flag = false;
		}
		cout << "Index=" << disk->getIndex() << endl;
        return flag;
	}
	bool deveriaRetornarManufacturer() {
        bool flag = true;
		if(disk->getManufacturer().empty()) {
			cerr << "Não retornou ManuFacturer" << endl;
            flag = false;
		}
		cout << "Manufacturer=" << disk->getManufacturer() << endl;
        return flag;
	}
	bool deveriaRetornarModel() {
        bool flag = true;
		if(disk->getModel().empty()) {
			cerr << "Não retornou  Model" << endl;
            flag = false;
		}
		cout << "Model=" << disk->getModel() << endl;
        return flag;
	}
	string deveriaRetornarName() {
        bool flag = true;
		if(disk->getName().empty()) {
			cerr << "Não retornou Name" << endl;
            flag = false;
		}
		string name = "\\\\\\\\.\\\\" + disk->getName().substr(4);
		return printString("Name", name);
		//cout << "Name=" << disk->getName() << endl;
        //return flag;
	}
	string deveriaRetornarPartitions() {
        bool flag = true;
		if(disk->getPartitionsCount() == 0) {
			cerr << "Não retornou Partitions" << endl;
            flag = false;
		}
		list<Partition*>parts = disk->getPartitions();
		list<Partition*>::iterator iter = parts.begin();
        list<Partition*>::iterator iterEnd = parts.end();

		bool flag_partitions = false;
        string str_temp = "\"Partitions\": [";
        while(iter != iterEnd) {			
			str_temp += "{";
			cout << "........................................................................." << endl;
			str_temp += printString("Letter", (*iter)->getLetter());
			cout << "Partitions Letter=" << (*iter)->getLetter() << endl;
            str_temp += ", ";
			str_temp += printString("VolumeName", (*iter)->getVolumeName());
			cout << "Partitions Volume Name=" << (*iter)->getVolumeName();
			cout << "........................................................................." << endl;
			str_temp += "}";

            iter++;
            if(iter != iterEnd) {
				str_temp += ",\n";
            }

		}		
        str_temp += "]";
        return str_temp;
	}
	bool deveriaRetornarPartitionsCount() {
        bool flag = true;
		if(disk->getPartitionsCount() == 0) {
			cerr << "Não retornou Partitions" << endl;
            flag = false;
		}
		cout << "Partitions=" << disk->getPartitionsCount() << endl;
        return flag;
	}
	bool deveriaRetornarPNPDeviceID() {
        bool flag = true;
		if(disk->getPNPDeviceID().empty()) {
			cerr << "Não retornou PNPDeviceID" << endl;
            flag = false;
		}
		cout << "PNPDeviceID=" << disk->getPNPDeviceID() <<endl;
        return flag;
	}
	bool deveriaRetornarSectorsPerTrack() {
        bool flag = true;
		if(disk->getSectorsPerTrack() == 0) {
			cerr << "Não retornou SectorsPerTrack" << endl;
            flag = false;
		}
		cout << "SectorsPerTrack=" << endl;
        return flag;
	}
	bool deveriaRetornarSerialNumber() {
        bool flag = true;
		if(disk->getSerialNumber().empty()) {
			cerr << "Não retornou Serial" << endl;
            flag = false;
		}
		cout << "Serial=" << disk->getSerialNumber() << endl; 
        return flag;
	}
	bool deveriaRetornarSize() {
        bool flag = true;
		if(disk->getSize() == 0) {
			cerr << "Não retornou Size" << endl;
            flag = false;
		}
		cout << "Size=" << disk->getSize() << endl;
        return flag;
	}
	bool deveriaRetornarStatus() {
        bool flag = true;
		if(disk->getStatus().empty()) {
			cerr << "Não retornou Status" << endl;
            flag = false;
		}
		cout << "Status=" << disk->getStatus() << endl;
        return flag;
	}
	bool deveriaRetornarStatusInfo() {
        bool flag = true;
		if(disk->getStatusInfo() == 0) {
			cerr << "Não retornou StatusInfo" << endl;
            flag = false;
		}
		cout << "StatusInfo" << disk->getStatusInfo();
        return flag;
	}
	bool deveriaRetornarTotalCylinders() {
        bool flag = true;
		if(disk->getTotalCylinders() == 0) {
			cerr << "Não retornou TotalCylinders" << endl;
            flag = false;
		}
		cout << "TotalCylinders=" << disk->getTotalCylinders() << endl;
        return flag;
	}
	bool deveriaRetornarTotalHeads() {
        bool flag = true;
		if(disk->getTotalHeads() == 0) {
			cerr << "Não retornou TotalHeads" << endl;
            flag = false;
		}
		cout << "TotalHeads=" << disk->getTotalHeads() << endl;
        return flag;
	}
	bool deveriaRetornarTotalSectors() {
        bool flag = true;
		if(disk->getTotalSectors() == 0) {
			cerr << "Não retornou TotalSectors" << endl;
            flag = false;
		}
		cout << "TotalSectors=" << disk->getTotalSectors() << endl;
        return flag;
	}
	bool deveriaRetornarTotalTracks() {
        bool flag = true;
		if(disk->getTotalTracks() == 0) {
			cerr << "Não retornou TotalTracks" << endl;
            flag = false;
		}
		cout << "TotalTracks=" << disk->getTotalTracks() << endl;
        return flag;
	}
	bool deveriaRetornarTracksPerCylinder() {
        bool flag = true;
		if(disk->getTracksPerCylinder() == 0) {
			cerr << "Não retornou TracksPerCylinder" << endl;
            flag = false;
		}
		cout << "TracksPerCylinder=" << disk->getTracksPerCylinder() << endl;
        return flag;
	}
};

#endif
