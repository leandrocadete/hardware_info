#ifndef ABSTTEST_H
#define ABSTTEST_H

#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isEmpty(string field, string value) {
    bool flag = true;
    if(value.empty()) {
        cerr << "Não retornou " << field << "!" << endl;
        flag = false;
    }
    cout << field << "=" << value << endl;
    return flag;
}

bool notZero(string field, uint32_t value) {
    bool flag = true;
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;
        flag = false;
    }
    cout << field << "=" << value << endl;
    return flag;
}

bool showBool(string field, bool value) {
    bool flag = true;
    if(value < 0 || value > 1) {
        cerr << field << " não é boolean!" << endl;
        flag = false;
    }
    cout << field << "=" << value << endl;
    return flag;
}



#endif // ABSTTEST_H
