#ifndef ARRAY_H
#define ARRAY_H

// extern const int ARRAY_SIZE = 100; // #define ARRAY_SIZE 100 // 컴파일시에 치환 되기때문에 형에 쫌더 업격하게 사용함

class Array{
private:
    static const int ARRAY_SIZE; // 전역변수인데 클레스에서관련돼서만 쓰인다는 의미 // public에 할당할경우 클레스이름을 통해서 전역에서 접근 할 수 있게됨
    int *pArr_;                                                                       // 자바에선 이 개념을 이용해서 전역변수개념을 사용하지 않음
    int size_;
public:
    // Array() {}
    // Array(const Array&){memberwise copy}
    // ~Array()
    // Array& operator=(const Array&){memberwise copy return this}
    // Array *operator&(){return this}일반객체
    // const Array *operator&() const {return this}상수객체
    explicit Array(int size = ARRAY_SIZE);   //명시적인 Array arr3 = 100 xxxx 형변환을 막음 
    Array(const int *pArr, int size = ARRAY_SIZE);
    Array(const Array& rhs);
    ~Array();

    Array& operator=(const Array& rhs);

    bool operator==(const Array& rhs)const;

    int& operator[](int index);   //일반객체
    const int& operator[](int index) const;  //상수객체 
    int size() const;
    
};

#endif