#ifndef TEST_NETWORK_ADAPTER_H
#define TEST_NETWORK_ADAPTER_H

#include "../Dao/DaoNetworkAdapter.h"
#include <string>

class ServiceNetworkAdapter {
private:
	DaoNetworkAdapter *dao;
	NetworkAdapter *adapter;
	list<NetworkAdapter*> adapters;
	NetworkAdapterConfiguration configuration;
	//ofstream file;
public:
	ServiceNetworkAdapter () {
		dao = new DaoNetworkAdapter();
	}
	~ServiceNetworkAdapter () { 
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
};

#endif
