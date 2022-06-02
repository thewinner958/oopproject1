#include <iostream>
#include <cstring>

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

String::String() {
    mString = nullptr;
}

String::String(char *string) {
    mString = strcpy(new char[strlen(string) + 1], string);
}

String::~String() {
    delete[] this->mString;
}

char * String::getString() const {
    return mString;
}

void String::setString(char *string) {
    if (mString == string) return;
    
    mString = strcpy(new char[strlen(string) + 1], string);
}
