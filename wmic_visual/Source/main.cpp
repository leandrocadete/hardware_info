#define MISSIN_ARGUMENT -1
#define TEST_MODE 1;

#include <nlohmann/json.hpp>
#include <iostream>
#include <Windows.h>
#include <comdef.h>
#include <WbemIdl.h>
#include <ctime>
#pragma comment(lib, "wbemuuid.lib")
#include <dciman.h>

#include "Service/serviceProcesses.h"
#include "Service/servicePhysicalDisk.h"
#include "Service/serviceMemory.h"
#include "Service/serviceNetworkAdapter.h"
#include "Service/serviceServices.h"
#include "Service/serviceCpu.h"

using namespace std;
using namespace nlohmann;

IWbemLocator* pLoc = NULL;
IWbemServices* pSvc = NULL;
void writeJson();
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
	cout << now->tm_year + 1900 << "/" << now->tm_mon + 1 << "/" << now->tm_mday << " " << now->tm_hour << ":" << now->tm_min << endl;
}

void help() {
	// TODO: To implement
}

void writeJson() {
	ofstream file;
	file.open("sysinfo.json", ios::trunc);
	json j;
	
	cout << "Begin" << endl;

	ServiceProcess* testProcess = new ServiceProcess();
	auto processes = testProcess->getProcess();
	while (!processes.empty()) {
		auto p = processes.top();

		j["Processes"] += {

			{ "Name", p->getName().c_str() },
			{ "Description", p->getDescription().c_str() },
			{ "CommandLine", p->getCommandLine().c_str() },
			{ "State", p->getExecutionState() }
		};
		processes.pop();
	}
	testProcess->~ServiceProcess();

	ServicePhysicalDisk* testPhysicalDisk = new ServicePhysicalDisk();
	auto disks = testPhysicalDisk->getPhysicalDisks();
	while (!disks.empty()) {
		auto d = disks.back();
		j["Disks"] += {
			{ "Name", d->getName() },
			{ "Caption", d->getCaption() },
			{ "Model", d->getModel() }
		};
		disks.pop_back();
	}
	testPhysicalDisk->~ServicePhysicalDisk();

	ServiceMemory* testMemory = new ServiceMemory();
	auto memories = testMemory->getMomories();
	while (!memories.empty()) {
		auto m = memories.back();
		j["Memories"] += {
			{ "Caption", m->getCaption() },
			{ "Capacity", m->getCapacity() },
			{ "BankLabel", m->getBankLabel() },
			{ "Speed", m->getSpeed() }
		};
		memories.pop_back();
	}
	testMemory->~ServiceMemory();

	ServiceNetworkAdapter* testNetworAdapter = new ServiceNetworkAdapter();
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
	testNetworAdapter->~ServiceNetworkAdapter();

	ServiceServices* testService = new ServiceServices();
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
	testService->~ServiceServices();

	ServiceCpu* testCpu = new ServiceCpu();
	auto cpus = testCpu->getCpus();
	while (!cpus.empty()) {
		auto c = cpus.back();
		j["CPU"] += {
			{ "Name", c->getName() },
			{ "Cores", c->getNumberOfCores() },
			{ "MaxClockSpeed", c->getMaxClockSpeed() },
			{ "Architecture", c->getArchitecture() },
			{ "Status", c->getStatus() }
		};
		cpus.pop_back();
	}
	testCpu->~ServiceCpu();
	std::streamsize size = j.dump().size();
	file.write(j.dump().c_str(), size);

	file.close();
}