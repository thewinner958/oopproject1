#include <iostream>
#include <cstring>

#pragma once

class String {
public:
    String();
    String(char *string);
    ~String();

    char *getString() const;

    void setString(char *string);

private:
    char *mString;

};

inline String::String() {
    mString = nullptr;
}

inline String::String(char *string) {
    mString = strcpy(new char[strlen(string) + 1], string);
}

inline String::~String() {
    delete[] this->mString;
}

inline char * String::getString() const {
    return mString;
}

inline void String::setString(char *string) {
    if (mString == string) return;
    
    mString = strcpy(new char[strlen(string) + 1], string);
}
