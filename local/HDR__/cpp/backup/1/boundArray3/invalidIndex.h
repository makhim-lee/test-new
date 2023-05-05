#ifndef INVALIDINDEX_H
#define INVALIDINDEX_H

class InvalidIndex {
private:
    int index_;

public:
    explicit InvalidIndex(int index);

    int invalid() const;
    
};



#endif