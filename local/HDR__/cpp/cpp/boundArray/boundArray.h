#include "safeArray.h"


class BoundArray : public SafeArray{
private:
    int low_;
public:
    explicit BoundArray(const int size = Array::ARRAY_SIZE);
    BoundArray(const int *Arr, const int size = Array::ARRAY_SIZE);
    BoundArray(const BoundArray& rhs);
    BoundArray(const int lower, const int upper);
    
    ~BoundArray();
    BoundArray& operator=(const BoundArray& rhs);
    bool operator==(const BoundArray& rhs) const;

    int lower() const;
    int upper() const;
};