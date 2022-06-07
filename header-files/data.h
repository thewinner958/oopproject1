#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>

#include "table.h"
#include "string.h"

using namespace std;


#ifndef OOPPROJECT1_DATA_H
#define OOPPROJECT1_DATA_H

class Data : public Table {
private:
    Table* table;

public:
    Data();
    Data(char* pathOfFile);
    ~Data();
};

inline Data::Data() : Table() {
    
}


#endif