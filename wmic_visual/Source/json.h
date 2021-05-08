#ifndef JSON_H
#define JSON_H

#include "win32.h"
#include <fstream>
#include <string>

//#include "DaoCpu.h"
//#include "DaoMemory.h"
//#include "DaoNetworkAdapter.h"
//#include "DaoPhysicalDisk.h"
//#include "DaoProcess.h"
//#include "daoservice.h"

#include "json_cpu.h"
#include "json_memory.h"
#include "json_processes.h"
#include "json_physicalDisk.h"
#include "json_service.h"

#include "testMemory.h"

//#include "json.cpp"
//extern Json json;

using namespace std;

class Json {
private:
    //char* fileName;
    char* fName;    
public:
    Json() {
        this->fName = new char[12];
        strcpy(fName, "sysinfo.json");
    }
    ~Json() {
        cout << "Object Json deleted!" << endl;
    }

    bool writeJson() {
        ofstream file(fName);
        if(!file.is_open()) {
            cerr << "Erro to open file:" << fName << endl;
            return false;
        }
        file << "[" << endl;

		JsonCpu jc(&file);
        jc.generateJson();
		jc.~JsonCpu();


		JsonMemory jm(&file);
		jm.gererateJson();
		jm.~JsonMemory();

        //append_Cpus(&file);
        //append_Memories(&file);
        append_network(&file);
        appped_Processes(&file);
        append_PhysicalDisk(&file);
        append_Services(&file);

        file << "]";
        file.close();
        return true;
    }

    bool append_Cpus(ofstream* file) {
        JsonCpu j(file);
        j.generateJson();
		j.~JsonCpu();
        return true;
    }
    bool append_PhysicalDisk(ofstream* file) {
        return true;
    }
    bool append_Services(ofstream* file){
        return true;
    }
    bool appped_Processes(ofstream* file) {
        return true;
    }
    bool append_Memories(ofstream* file) {
        JsonMemory j(file);
        j.gererateJson();
		j.~JsonMemory();
        //TestMemory m;
        //m.test();
        return true;
    }
    bool append_network(ofstream* file) {
        return true;
    }

};
#endif // JSON_H
