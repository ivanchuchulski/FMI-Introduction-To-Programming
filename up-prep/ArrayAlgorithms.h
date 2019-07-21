#pragma once

#include <utility>		//for std::swap




namespace arralg {


	//_> returns the index first occurence of the elemement, -1 otherwise
	int LinearSearch(const double* arr, const size_t size, const double elementToFind)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == elementToFind)
			{
				return i;
			}
		}

		//if not found
		return -1;
	}

	//_> the array must be sorted
	int BinarySearch(const double* arr, const size_t size_arr, const double elementToFind)
	{
		size_t LeftSide = 0;
		size_t RightSide = size_arr - 1;

		while (LeftSide <= RightSide)
		{
			int Middle = (RightSide - LeftSide) / 2;

			if (arr[Middle] == elementToFind)
			{
				return Middle;
			}
			else if (arr[Middle] < elementToFind)
			{
				RightSide = Middle - 1;
			}
			else		//arr[Middle] > elementToFind
			{
				LeftSide = Middle - 1;
			}

		}

		//if not found
		return -1;
	}


	//_>
	void SelectionSort(double* arr, const size_t size_arr)
	{
		size_t MinInd;

		for (size_t i = 0; i < size_arr; i++)
		{
			MinInd = i;
			for (size_t j = i + i; j < size_arr; j++)
			{
				if (arr[j] < arr[MinInd])
				{
					MinInd = j;
				}
			}

			if (MinInd != i)
			{
				
				std::swap(arr[i], arr[MinInd]);
			}
		}

	}



}