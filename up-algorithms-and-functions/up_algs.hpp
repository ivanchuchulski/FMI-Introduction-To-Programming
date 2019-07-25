//algorithms from the Introduction to programming course

#ifndef UP_ALGS_H
#define UP_ALGS_H

#include <algorithm>		//std::swap


	// --------------------------Searching--------------------------

	int LinearSearch(const double* arr, const size_t size, const double element)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == element)
				return i;
		}

		//error code, element not found
		return -1;
	}

	int BinarySearch(const double* arr, const size_t size, const double element)
	{
		int left = 0;
		int right = size - 1;

		while (left <= right)
		{
			int middle = (left + right) / 2;

			if (arr[middle] == element)
				return middle;

			else if (arr[middle] > element)
				right = middle - 1;

			else  //arr[middle] < element
				left = middle + 1;
		}

		// error, element not found
		return -1;
	}


	// --------------------------Sorting--------------------------

	//sorting in ascending order
	void BubbleSortV1(double* arr, size_t size)
	{
		size_t rightmost = size - 1;

		for (size_t i = 0; i < rightmost; i++)
		{
			for (size_t j = rightmost; j > i; j--)
			{
				if (arr[j - 1] > arr[j])
					std::swap(arr[j - 1], arr[j]);
			}
		}
	}

	//sorting in ascending order
	void SelectionSort(double* arr, size_t size)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			size_t min_index = i;

			for (size_t j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[min_index])
					min_index = j;
			}

			if (min_index != i)
				std::swap(arr[min_index], arr[i]);
		}
	}


	void BubbleSort(double* arr, size_t size)
	{
		bool swap_occured = false;

		for (size_t i = 0; i < size - 1; i++)
		{
			bool swap_occured = false;
			for (size_t j = 0; j < size - i - 1; j++)
			{
				if (arr[j + 1] < arr[j])
				{
					std::swap(arr[j + 1], arr[j]);
					swap_occured = true;
				}
			}

			if (!swap_occured)
			{
				break;
			}
		}
	}


#endif UP_ALGS_H