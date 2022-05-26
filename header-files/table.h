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
    fstream _inputFile;
    ofstream _outputFile;
public:
    /**
     * @brief Construct a new Table object
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

Table::Table(char * pathOfFile) {
    _pathOfFile = strcpy(new char[strlen(pathOfFile) + 1], pathOfFile);
}

Table::~Table() {
    delete[] this ->_pathOfFile;
}

void Table::openFile() {
    if (!_inputFile.is_open()) _inputFile.open(_pathOfFile);
}

void Table::closeFile() {
    if (_inputFile.is_open())
    {
        _inputFile.close();
    }
}

#endif //OOPPROJECT1_TABLE_H
