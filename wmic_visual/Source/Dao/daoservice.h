#ifndef DAOSERVICE_H
#define DAOSERVICE_H

#include "../Model/win32.h"
#include "../Model/service.h"
#include <list>
class DaoService : private Win32Objs {
private:
    Service* service;
    list<Service*> services;
public:
    DaoService();
    ~DaoService();
    list<Service*> loadServices();
    list<Service *> getServices() const;
};

#endif // DAOSERVICE_H
