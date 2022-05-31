#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>

using namespace std;


#ifndef OOPPROJECT1_TABLE_H
#define OOPPROJECT1_TABLE_H
/**
 * @brief This class is the main one that i am gonna use
 * 
 */
class Table {
private:
    char * _pathOfFile;
    fstream _file;
    char * _columns;
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
    _pathOfFile = nullptr;
}

Table::Table(char * pathOfFile) {
    _pathOfFile = strcpy(new char[strlen(pathOfFile) + 1], pathOfFile);
}

Table::~Table() {
    delete[] this ->_pathOfFile;
}

void Table::openFile() {
    if (_pathOfFile == nullptr) cout << "You have not specified a path of a file" << endl;
    if (!_file.is_open()) _file.open(_pathOfFile);
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
