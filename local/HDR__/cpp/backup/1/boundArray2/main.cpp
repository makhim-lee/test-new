#include <iostream>
#include "boundArray.h"
#include "complex.h"

int main()
{
	BoundArray<int> arr1(1, 11);
	for (int i = arr1.lower(); i < arr1.upper(); ++i) {
		arr1[i] = i;
	}
	
	for (int i = arr1.lower(); i < arr1.upper(); ++i) {
		std::cout << "arr1[" << i << "] : " << arr1[i] <<std::endl;
	}
		
	Complex nums[] = {Complex(3.0, 4.0), Complex(3.0), Complex(), 3.0};
	BoundArray<Complex> arr2(nums, 4);
	
	for (int i = arr2.lower(); i < arr2.upper(); ++i) {
		std::cout << "arr2[" << i << "] : " << arr2[i] << std::endl;
	}
	
	return 0;
}
