#include <iostream>
#include <vector>
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
    vector<char *> mData;
public:
    Data();
    Data(const Table& table);
    ~Data();
};

inline Data::Data() : Table() {
    mData.end();
}

Data::Data(const Table& table) : Table(table){
    char * temp = getTable();
    for (int i = 0; i < sizeof(temp); ++i) {

    }
}


#endif