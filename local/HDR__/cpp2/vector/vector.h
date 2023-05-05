#ifndef VECTOR_H
#define VECTOR_H

#include<algorithm>
#include<memory>
namespace iot {    

template <typename T>
class Vector{
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* iterator ;
    typedef const T* const_iterator ;
    typedef T& reference_type;
    typedef const T& const_reference_type;

    Vector();
    explicit Vector(size_type n, const_reference_type value = T());// T() --> int 의 디폴트 생성자 
    Vector(const_iterator b, const_iterator e);
    Vector(const Vector<T>& rhs);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& rhs);
    bool operator==(Vector<T>& rhs) const;

    reference_type operator[](int index);
    const_reference_type operator[](int index)const;

    iterator begin();
    iterator end();
    const_iterator cbegin()const;
    const_iterator cend()const;

    size_type size() const;
    
    void push_back(const value_type &value);

private:
    std::allocator<value_type> alloc;
    iterator data;
    iterator avail;
    iterator limit;

    void create(size_type n, const value_type& value);
    void create(const_iterator b, const_iterator value);
    void uncreate();
    void grow();
    void append(const value_type& value);
};

template <typename T>
void Vector<T>::create(size_type n, const value_type& value){
    this->data = this->alloc.allocate(n);
    std::uninitialized_fill(this->data, this->data + n, value);
    this->limit = this->data + n;
    this->avail = this->limit;
}

template <typename T>
void Vector<T>::create(const_iterator b, const_iterator e){
    this->data = this->alloc.allocate(e - b);
    this->limit = std::uninitialized_copy(b, e, this->data);
    this->avail = this->limit;
}

template <typename T>
void Vector<T>::uncreate(){
    if(this->data){
        iterator it = this->data;
        while(it != this->avail){
            this->alloc.destroy(it);
            ++it;
        }
        this->alloc.deallocate(this->data, this->limit - this->data);
    }
}

template <typename T>
void Vector<T>::grow(){  //vector 크기 2배 늘리기 
    size_type new_size = (this->data == 0)? 2 * (this->limit - this->data) : 1;
    iterator new_data = this->alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(this->data, this->avail, new_data);
    
    this->uncreate();

    this->data = new_data;
    this->avail = new_avail;
    this->limit = this->data + new_size;
}

template <typename T>
void Vector<T>::append(const value_type& value){
    this->alloc.construct(this->avail, value);
    ++this->avail;
}

template <typename T>
Vector<T>::Vector()
: data(0), avail(0), limit(0)
{

}

template <typename T>
Vector<T>::Vector(size_type n, const_reference_type value){
    this->create(n, value);
}

template <typename T>
Vector<T>::Vector(const_iterator b, const_iterator e){
    this->create(b, e);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs){
    this->create(rhs.cbegin(), rhs.cend());
}

template <typename T>
Vector<T>::~Vector(){
    this->uncreate();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs){
    if(this != &rhs){
        this->uncreate();
        this->create(rhs.cbegin(), rhs.cend());
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator==(Vector<T>& rhs) const{
    return std::equal(this->cbegin(), this->cend(), rhs.cbegin());
}

template <typename T>
typename Vector<T>::reference_type Vector<T>::operator[](int index){
    return this->data[index];
}

template <typename T>
typename Vector<T>::const_reference_type Vector<T>::operator[](int index)const{
    return this->data[index];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin(){
    return this->data;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end(){
    return this->avail;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin()const{
    return this->data;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend()const{
    return this->avail;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::size()const{
    return avail - data;
}

template <typename T>
void Vector<T>::push_back(const value_type &value){
    if(this->avail == this->Limit){//full?
        this->grow();
    }

    this->append(value);
    //input ?
}

} // namespace iot

#endif  

