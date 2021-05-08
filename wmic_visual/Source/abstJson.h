#ifndef ABSJSON_H
#define ABSJSON_H
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;


string printString(string field, char* v) {
    string value(v);
	//value.replace(
    string temp =  "\"";
    if(value.empty()) {
        cerr << "Não retornou " << field << "!!" << endl;
        temp.append(field);
        temp.append("\":null");
    }else {
        temp.append(field);
        temp.append("\":\"");
        temp.append(value);
        temp.append("\"");
    }
    //temp.append(",\n");
    return temp;
}

string printString(string field, string value) {
    string temp =  "\"";
    if(value.empty()) {
        cerr << "Não retornou " << field << "!!" << endl;
        temp.append(field);
        temp.append("\":null");
    }else {
        temp.append(field);
        temp.append("\":\"");
        temp.append(value);
        temp.append("\"");
    }
    //temp.append(",\n");
    return temp;
}

string printString(string field, uint32_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;        
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printUint32(string field, uint32_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;        
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printString(string field, uint16_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printUint16(string field, uint16_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printString(string field, uint64_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printUint64(string field, uint64_t value) {
    string temp =  "\"";
    if(value == 0) {
        cerr << field << " retornou zero!" << endl;
    }
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    ///temp.append(",\n");
    return temp;
}

string printString(string field, bool value) {
    string temp =  "\"";
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

string printBool(string field, bool value) {
    string temp =  "\"";
    temp.append(field);
    temp.append("\":");
    temp.append(to_string(value));
    //temp.append(",\n");
    return temp;
}

#endif // ABSTTEST_H
