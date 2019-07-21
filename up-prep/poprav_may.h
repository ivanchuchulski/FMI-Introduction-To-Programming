/*
	Write functions that return a boolean answer to :

	->task1 : check if a given string in the format "YYYY g." is a leap year
				(just check if it is divisable by 4)

	->task2 : given 2 integer arrays and their sizes, check if the first is a subset of the second

	->task3 : given a string, check if there are 3 continious ascii characters one after another
				example : "abc", "012", "cba", "210"

*/

#pragma once

#include "CStringFuncs.h"


//_> function finding the minimum of two integers
int Minimal(const int a, const int b)
{
	return (a > b) ? (a) : (b);
}

//_> task2
bool IsSubset(const char* SetA, const char* SetB, const int a_len, const int b_len)
{
	//null check
	if (SetA == nullptr || SetB == nullptr)
		return false;

	//either or both empty set checks
	if (a_len == 0 && b_len == 0)
		return true;
	else if (a_len == 0 && b_len > 0)
		return true;
	else if (b_len == 0 && a_len > 0)
		return true;


	if (a_len < b_len)
		return false;

	bool element_found = false;
	
	//each in the one with smaller size, has to be included int the bigger one
	for (int i = 0; i < a_len; i++)
	{
		element_found = false;
		//searching for each in the one with bigger size
		for (int j = 0; j < b_len; j++)
		{
			if (SetA[i] == SetA[j])
			{
				element_found = true;
				break;
			}
		}

		if (element_found == false)
		{
			return false;
		}
	}


}


//_> task3
/*			
		0 1 2 3			lenght = 4 ;  len - 2 = 2
		q b c d  

*/
bool IsCorrect(const char* input)
{
	unsigned int length = cstr::StrLen(input);

	bool correct = false;

	for (unsigned int i = 0; i < length - 2; i++)
	{
		//ascii codes descending
		if (  ( input[i] == (input[i + 1] - 1) ) && ( input[i] == (input[i + 2] - 2) )  )
		{
			correct = true;
			break;
		}

		//ascii codes ascending
		else if (  ( input[i] == (input[i + 1] + 1) ) && ( input[i] == (input[i + 2] + 2) )  )
		{
			correct = true;
			break;
		}
	}

	return correct;
}


int Power(int base, int power)
{
	if (power < 0)
	{
		std::cout << "Opa, negative power\n";
		return -1;
	}

	//cheking for zero power
	if (power == 0)
		return 1;

	int result = 1;
	for (unsigned int i = 1; i <= power; i++)
	{
		result *= base;
	}

	return result;
}

//_> task1
bool LeapYear(const char* input)
{
	//checking for correct format	: "YYYY g."

	const size_t FORMAT_LENGTH = 7;

	if (input == nullptr)
		return false;

	size_t length_of_input = cstr::StrLen(input);

	if (length_of_input != FORMAT_LENGTH)
		return false;

	if (input[4] != ' ' || input[5] != 'g' || input[6] != '.')
		return false;

	int yearAsNumber = 0;
	unsigned int digits = length_of_input - 3;		// 4

	for (int i = 0; i < FORMAT_LENGTH - 3; i++)
	{
	//	yearAsNumber += cstr::ToInt(input[i]) * Power(10, digits - 1 - i);
		yearAsNumber += cstr::ToInt(input[i]) * Power(10, --digits);
	}

	if (yearAsNumber % 4 == 0)
		return true;
	else
		return false;
}


