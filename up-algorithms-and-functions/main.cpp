#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include "alg.h"
#include "up_algs.hpp"		//also includes <algorithm>

void Print2DVector(std::vector<std::vector<int>>& vec)
{
	std::cout << "size : " << vec.size() << '\n';

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec.size(); j++)
		{
			std::cout << vec[i][j] << ' ';
		}

		std::cout << '\n';
	}
}


int main() {

	std::array<double, 5> arr1 = { 1.0, 5.0, 6.0, 12.0, 7.0 };
	std::array<double, 5> arr2 = { 5.0, 2.0, 11.0, 7.0, 8.0 };

	//SelectionSort(arr2.data(), arr2.size());
	BubbleSort(arr2.data(), arr2.size());

	BubbleSort(arr1.data(), arr1.size());

	BinarySearch(arr1.data(), arr1.size(), -1);

	std::vector<std::vector<int>> v = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//	Print2DVector(v);

	auto VecIsEmpty = [&v]() -> bool 
	{
		return v.empty(); 
	};

	std::cout << VecIsEmpty() << std::endl;


	std::system("pause");
	return 0;
}