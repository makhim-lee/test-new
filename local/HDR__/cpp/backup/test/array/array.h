

class Array{
private:
    int size_
    int *pArr_

pubilc:
    Array(const int size, Array& rhs);   //Array a = b
    Array(const int* pArr ,const int size = 100);         //Array a(num[], size)
    Array(const int size = 100);     //Array a(size)
    ~Array();

    Array& operator=(const Array& rhs);  //a = b
    Array operator+(const Array& rhs); //c1=c3.operator+(c2)  --> c1 = c3 + c2
    bool operator==(const Array& rhs);  //  c1.operator==(c3) --> c1 == c3

    int& operator[](const int index);
    const int& operator[](const int index);
    int size();

};