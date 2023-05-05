#ifndef STRING_H
#define STRING_H
#include<iostream>

class String{
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
    char *str;
    int len;//size_t len;



public:
    // default 함수 
    //String() {}   //inlien 함수
    //String(const String& rhs) {membberwise copy}
    //~String();
    // String& operator=(const String& rhs) {membberwise copy; return *this;}
    // String *operator&() {return this;}
    // const String *operator&() const {return this;}

    String();
    String(const char *s);
    String(const String& rhs);
    ~String();

    const char *c_str();
    int size();
    // +=, *=
    bool operator==(const String& rhs);
    bool operator!=(const String& rhs);
    // !=, >, <, >=, <=
    
    String& operator=(const String& rhs);
    // String& operator=(const char *s);  컴파일러 default랑 거의 유사함 
    const String operator+(const String& rhs);
};


#endif