#define MISSIN_ARGUMENT -1
#define TEST_MODE 1;

#include <nlohmann/json.hpp>
#include <iostream>
#include <Windows.h>
#include <comdef.h>
#include <WbemIdl.h>
#include <ctime>

using namespace std;
using namespace nlohmann;

#pragma comment(lib, "wbemuuid.lib")
#include <dciman.h>

IWbemLocator *pLoc = NULL;
IWbemServices *pSvc = NULL;

void writeJson();

#include "Service/testProcesses.h"
#include "Service/testPhysicalDisk.h"
#include "Service/testMemory.h"
#include "Service/testNetworAdapter.h"
#include "Service/testservice.h"
#include "Service/testcpu.h"

void help();
void printTime();

int main(int argc, char** argv) {
	SetConsoleOutputCP(CP_UTF8);
	writeJson();
	printTime();
    return 0;
}

void printTime() {
	time_t t = time(0);
    struct tm* now = localtime(&t);
    cerr << now->tm_year + 1900 << "/" << now->tm_mon + 1 << "/" << now->tm_mday << " " << now->tm_hour << ":" << now->tm_min << endl;
    cout << now->tm_year + 1900 << "/" << now->tm_mon + 1 << "/" << now->tm_mday << " " << now->tm_hour << ":" << now->tm_min << endl;
}

void help() {
    cout << "Usage: sysinfo argument" << endl;
    cout << "\t -j Generate json file as output" << endl;
    cout << "\t -t Test mode" << endl;

}

void writeJson() {
	bool flag = true;
	ofstream file;
	file.open("sysinfo.json", ios::trunc);
	json j;
	
	cout << "inicio" << endl;
	TestProcess *testProcess = new TestProcess();
	auto processes = testProcess->getProcess();
	while (!processes.empty()) {
		auto p = processes.top();
		
		j["Processes"] += {
			{"Name", p->getName().c_str()},
			{"State", p->getExecutionState()},
		};
		processes.pop();
	}
	//printf("%s", j.dump().c_str());
	testProcess->~TestProcess();

	TestPhysicalDisk *testPhysicalDisk = new TestPhysicalDisk();
	auto disks = testPhysicalDisk->getPhysicalDisks();
	while (!disks.empty()) 	{
		auto d = disks.back();
		j["Disks"] += {
			{ "Name", d->getName() },
			{ "Caption", d->getCaption() },
			{ "Model", d->getModel() }
		};
		disks.pop_back();
	}
	testPhysicalDisk->~TestPhysicalDisk();

	TestMemory *testMemory = new TestMemory();
	auto memories = testMemory->getMomories();
	while (!memories.empty()) {
		auto m = memories.back();
		j["Memories"] += {
			{ "Caption", m->getCaption() },
			{ "Capacity", m->getCapacity() },
			{ "BankLabel", m->getBankLabel() }
		};
		memories.pop_back();
	}
	testMemory->~TestMemory();

	TestNetworkAdapter *testNetworAdapter = new TestNetworkAdapter();
	auto networkAdapters = testNetworAdapter->getNetworkAdapters();
	while (!networkAdapters.empty()) {
		auto adapter = networkAdapters.back();
		j["NetworkAdapters"] += {
			{ "Name", adapter->getName() },
			{ "Adresses", adapter->getNetworkAdapterConfiguration().getIPAddress() },
			{ "Name", adapter->getName() }
		};
		networkAdapters.pop_back();
	}
	testNetworAdapter->~TestNetworkAdapter();

	TestService *testService = new TestService();
	auto services = testService->getServices();
	while (!services.empty()) {
		auto s = services.back();
		j["Services"] += {
			{ "Name", s->getName() },
			{ "State", s->getState() },
			{ "StartMode", s->getStartMode() }
		};
		services.pop_back();
	}
	testService->~TestService();

	TestCpu *testCpu = new TestCpu();
	auto cpus = testCpu->getCpus();
	while (!cpus.empty()) {
		auto c = cpus.back();
		j["CPU"] += {
			{ "Name", c->getName() },
			{ "Cores", c->getNumberOfCores() },
			{ "Cores", c->getMaxClockSpeed() }
		};
		cpus.pop_back();
	}
	testCpu->~TestCpu();
	std::streamsize size = j.dump().size();
	file.write(j.dump().c_str(), size);
		
	file.close();
}