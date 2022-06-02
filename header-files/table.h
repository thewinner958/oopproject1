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
private:
    String _pathOfFile;
    fstream _file;
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
    ~Table();

    void openFile();
    void closeFile();
};

Table::Table() {
    _pathOfFile.setString(nullptr);
}

Table::Table(char * pathOfFile) {
    _pathOfFile.setString(pathOfFile);
}

Table::~Table() {
    
}

void Table::openFile() {
    if (_pathOfFile.getString() == nullptr) cout << "You have not specified a path of a file" << endl;
    if (!_file.is_open()) _file.open(_pathOfFile.getString());
    else cout << "File is already in use" << endl;
}

void Table::closeFile() {
    if (_file.is_open())
    {
        _file.close();
    }
    else cout << "File is alredy not being used" << endl;
}

#endif //OOPPROJECT1_TABLE_H
