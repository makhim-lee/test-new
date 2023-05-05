#include <iostream>
#include "safeArray.h"
#include "invalideIndex.h"

int main()
{
	int nums1[] = {1, 2, 3, 4, 5};
	Array<int> arr1(nums1, 5);
	

try{
	for (int i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << std::endl;
	}
	
	double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	SafeArray<double> arr2(nums2, 5);

	for (int i = 0; i < arr2.size(); ++i) {
		std::cout << arr2[i] << std::endl;
	}

	arr2[5] = 6.6; 
} catch (const InvalidIndex& e){
	std::cerr << "array boundary error index: " << e << std::endl;  // cerr :: 버퍼를 거치지 않고 출력
}
// } catch (double e){
// } catch( )//....

	return 0;
}
