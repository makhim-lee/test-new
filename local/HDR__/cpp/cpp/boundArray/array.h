#ifndef ARRAY_H
#define ARRAY_H

class Array{
private:
    int *pArr_;                  
protected:
    static const int ARRAY_SIZE; 
    int size_;
public:
    explicit Array(int size = ARRAY_SIZE);   
    Array(const int *pArr, int size = ARRAY_SIZE);
    Array(const Array& rhs);
    virtual ~Array();

    Array& operator=(const Array& rhs);

    bool operator==(const Array& rhs)const;

    virtual int& operator[](int index);   //일반객체
    virtual const int& operator[](int index) const;  //상수객체 
    int size() const;
    
};

#endif