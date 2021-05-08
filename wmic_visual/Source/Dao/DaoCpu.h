#ifndef DAOCPU_H
#define DAOCPU_H

#include "../Model/win32.h"
#include "../Model/CPU.h"
#include <list>

class DaoCpu : private Win32Objs {
private:
    list<CPU*> cpus;
    CPU *cpu;    
public:
    ~DaoCpu();
    DaoCpu();
    list<CPU*> loadCpus();
    list<CPU*> getCpus() { return cpus; }
};

#endif // DAOCPU_H
