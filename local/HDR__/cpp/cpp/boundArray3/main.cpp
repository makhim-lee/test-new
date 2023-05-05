#include <iostream>
#include "boundArray.h"
#include "complex.h"
#include"invalidIndex.h"
#include<stdexcept>
#include<string>

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
try{
	arr2[4] = arr2[0];
} catch (const std::domain_error& e){
	std::cerr << e.what()<<std::endl;
} //catch(const InvalidIndex& e){
	//std::cerr << "array boundary error index: " << e.invalid() << std::endl;
//} 

	
	return 0;
}
