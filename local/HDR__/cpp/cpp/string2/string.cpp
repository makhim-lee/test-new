#include<iostream>
#include<cstring>
#include<cassert>
#include"string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs){
    //return out << rhs.rep_->str_;
    return out << rhs.c_str();
}

String::String(){
    rep_ = new StringRep();
    assert(rep_);
    rep_->rc_ = 1;
}

String::String(const char *s){
    rep_ = new StringRep(s);
    rep_->rc_ = 1;
}

String::String(const String& rhs){
    rep_ = rhs.rep_;
    ++rep_ -> rc_;
}
String::~String(){
    --rep_ = rep_;
    ++rep_ -> rc_;
}



String& String::operator=(const String& rhs){
    if (this != &rhs){
        --rep_->rc_;
        if(rep_->rc_ == 0){
            delete rep_;
        }
        rep_=rhs.rep_;
        ++rep_->rc_;
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
    return strcmp(rep_->str_, rhs.rep_->str_) == 0;
}

bool String::operator!=(const String& rhs){
    return !this->operator==(rhs);
}

const String String::operator+(const String& rhs){
    char *buf = new char[rep_->len_ + rhs.rep_->len_ + 1];
    assert(buf );
    strcpy(buf, rep_->str_);
    strcat(buf, rhs.rep_->str_);

    String result(buf);
    delete [] buf;
    return result;
}

const char *String::c_str()const{
    return rep_->str_;
}
int String::size()const{
    return rep_->len_;
}

