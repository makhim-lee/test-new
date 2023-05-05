#ifndef STRINGREP_H
#define STRINGREP_H

class StringRep{
friend class String;

private:
    char *str_;
    int len_;
    int rc_;

    StringRep();
    StringRep(const char *s);
    ~StringRep();

public:

};

#endif