#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
 
#include "string.h"

using namespace std;


#ifndef OOPPROJECT1_TABLE_H
#define OOPPROJECT1_TABLE_H



/**
 * @brief This is the base class of the whole program
 * 
 */
class Table {
protected:
    String _pathOfFile;
    fstream _file;
    String _table;
public:
    /**
     * @brief Construct a default Table object
     * 
     */
    Table();
    /**
     * @brief Construct a Table object
     * 
     * @param pathOfFile 
     */
    Table(char * pathOfFile);
    /**
     * @brief Destroy the Table object
     * 
     */
     Table(const Table& other);
    ~Table();

    char* getTable() const;
    int getLineCount() const;
    void openFile();
    void closeFile();

    
};

inline Table::Table() {
    _pathOfFile.setString(nullptr);
}

inline Table::Table(char * pathOfFile) {
    _pathOfFile.setString(pathOfFile);
    char *temp;
    openFile();
    _file >> temp;
    _table.setString(temp);
    delete temp;
}

inline Table::~Table() {
    closeFile();
}

inline void Table::openFile() {
    if (_pathOfFile.getString() == nullptr) cout << "You have not specified a path of a file" << endl;
    if (!_file.is_open()) _file.open(_pathOfFile.getString());
    else cout << "File is already in use" << endl;
}

inline void Table::closeFile() {
    if (_file.is_open())
    {
        _file.close();
    }
    else cout << "File is alredy not being used" << endl;
}

inline char* Table::getTable() const {
    return _table.getString();
}

inline int Table::getLineCount() const{
    int count = 0;
    char* temp = _table.getString();
    for (int i = 0; i < sizeof(temp); i++) {
        if (temp[i] == '\n') {
            count++;
        }
    }
    delete temp;
    return count;
}

Table::Table(const Table &other) {
    _pathOfFile = other._pathOfFile;
    _table = other._table;
}

class Data;

#endif //OOPPROJECT1_TABLE_H
