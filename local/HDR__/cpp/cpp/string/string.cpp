#include<cstring>
#include<cassert>
#include"string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs){
    return out << rhs.str;
}

String::String(){
    //this->str = new char;  <-- delete p; 
    this->str = new char[1];
    assert(this->str);
    this->str[0] = '\0';
    this->len = 0;
}

String::String(const char *s){
    this->str = new char[strlen(s) + 1];
    assert(this->str);
    strcpy(this->str, s);
    this->len = strlen(s);
}

String::String(const String& rhs){
    this->str = new char[rhs.len +1];
    assert(this->str );
    strcpy(this->str, rhs.str);
    this->len = rhs.len;
}

const char *String::c_str(){
    return this->str;
}
int String::size(){
    return this->len;
}

String& String::operator=(const String& rhs){
    if (this != &rhs){
        delete [] this->str;   
        this->str = new char[rhs.len + 1];
        assert(this->str );
        strcpy(this->str, rhs.str);
        this->len = rhs.len;
    }
    return *this;
}

// String& String::operator=(const char *s){
//     if(this != s){
//         delete [] this->str;
//         this->str = new char[rhs.len + 1];
//         assert(this->str );
//         strcpy(this->str, s);
//         this->len = strlen(s);
//     }
//     return *this;
// }

bool String::operator==(const String& rhs){
    return strcmp(this->str, rhs.str) == 0;
}

bool String::operator!=(const String& rhs){
    return !this->operator==(rhs);
}

const String String::operator+(const String& rhs){
    char *buf = new char[this->len + rhs.len + 1];
    assert(buf );
    strcpy(buf, this->str);
    strcat(buf, rhs.str);

    String result(buf);
    delete [] buf;
    return result;
}

String::~String(){
    delete[] this->str;
}
