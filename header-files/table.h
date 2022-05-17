#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>

using namespace std;


#ifndef OOPPROJECT1_TABLE_H
#define OOPPROJECT1_TABLE_H

class Table {
private:
    char * _pathOfFile; //a parameter for the path of the file
    fstream _inputFile;
    ofstream _outputFile;
public:
    Table(char * pathOfFile); //Constructor with the path of file parameter set by the user

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
