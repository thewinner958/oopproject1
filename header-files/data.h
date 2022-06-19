#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <exception>

#include "table.h"
#include "string.h"

#define BUFFER 1000000000

using namespace std;


#ifndef OOPPROJECT1_DATA_H
#define OOPPROJECT1_DATA_H

class Data : public Table {
private:
    vector<char *> mData;
    int mNumberOfData = 0;
    int mColumns = 0;
    int mLines = 0;
public:
    Data();
    Data(const Table& table);
    ~Data() = default;
};

inline Data::Data() : Table() {
    mData[0] = nullptr;
}

Data::Data(const Table& table) : Table(table){
    char * tempTable = getTable();
    char * temp = nullptr;
    int tempColumns = 0;
    for (int i = 0; i < sizeof(tempTable); ++i) {
        if (tempTable[i] == ',') {
            for (int j = 0; j < BUFFER; ++j) {
                if (mData[j] != nullptr) {
                    continue;
                } else {
                    mData[j] = temp;
                    mNumberOfData++;
                    temp = nullptr;
                    break;
                }
            }
            tempColumns++;
        }
        if (tempTable[i] == '\n') {
            mLines++;
            if (mColumns == 0) mColumns = tempColumns;
            else if (mColumns != 0 && tempColumns > mColumns) {
                mColumns = tempColumns;
            } else mColumns = mColumns;
            tempColumns = 0;
            temp = nullptr;
            continue;
        }
        temp += tempTable[i];
    }
}


#endif