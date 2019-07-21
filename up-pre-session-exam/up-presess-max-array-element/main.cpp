/* Find the maximum element in a integer array and return it
	_>dynamic memory variant
*/
#include <iostream>

// _? : int* &myArr, as a function parameter
void setArray(int* myArr, size_t sizeArr) {
	size_t i = 0;

	std::cout << "Setting array..." << std::endl;
	for (i; i < sizeArr; i++) {

		//std::cout << "arr[" << i << "] = ";
		//std::cin >> myArr[i];

		std::cout << "arr[" << i << "] , ";
		myArr[i] = 0;
	}

	std::cout << '\n';
}

//finding max element
int maxElement(int *a, int len) {
	int max = 0;

	for (int i = 0; i < len; i++) {
		if (a[i] >= max) {
			max = a[i];
		}
	}
	//returning
	return max;
}

//driver programme
int main() {
	size_t n;
	int *arr = NULL;

	//getting user input
	std::cout << "Enter n : ";
	std::cin >> n;

	//creating dynamic array
	arr = new int[n];

	//check for valid memory allocation
	if (arr == nullptr) {
		std::cout << "Memory error" << std::endl;
		system("pause");
		return 0;
	}

	setArray(arr, n);

	int maximum = maxElement(arr, n);
	std::cout << "maximum : " << maximum << std::endl;

	std::cout << std::endl;
	system("pause");
	return 0;
}