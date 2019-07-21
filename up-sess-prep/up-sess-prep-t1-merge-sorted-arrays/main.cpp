#include <iostream>
#include <iomanip>
#include <algorithm>

void PrintArr(int *arr, size_t n) 
{
	for (size_t i = 0; i < n; i++)
		std::cout << arr[i] << " ";

	std::cout << "\n";
}


/*				4 1 2 3 5 
				1 4 2 3 5

*/
void SelectionSort(int* arr, size_t n)
{
	size_t minInd = 0;

	for (size_t i = 0; i < n; ++i)
	{
		minInd = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minInd])
			{
				minInd = j;
			}
		}
		
		if (minInd != i)
		{
			std::swap(arr[i], arr[minInd]);
		}

	}

}


int* MergeArrays(const int* first, const size_t size_first, const int* second, const unsigned size_second)
{
	size_t result_size = size_first + size_second;
	int* dest = new int[result_size];

	//copying from the first
	for (size_t i = 0; i < size_first; i++)
		dest[i] = first[i];

	//copying from the second
	size_t int k = 0;
	for (unsigned j = size_first; j < result_size; j++)
		dest[j] = second[k++];

	std::cout << "Merged arrays : \n";
	PrintArr(dest, result_size);

	std::cout << "sorting... \n";
	SelectionSort(dest, result_size);

	return dest;
}

int main() {
	/* Petio said that the last digit of the egn can be used to determine the sex of the person 
	long long egn = 9803231456;
	int sex = (egn % 10);

	cout << egn << endl;
	cout << sex << endl;

	cout << "birthyear : 19" << egn / 100000000 << endl;
	if (sex % 2 == 0) {
		cout << "male\n";
	}
	else
		cout << "female\n";
	*/

	int a[] = { 3, 5, 7, 9, 11 };
	int b[] = { 1, 2, 4, 6, 8, 10 };

	int* c = MergeArrays(a, 5, b, 6);
	PrintArr(c, 11);

	delete[] c;

	std::cin.get();
	return 0;
}