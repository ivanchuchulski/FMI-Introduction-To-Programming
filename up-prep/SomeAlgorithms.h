#pragma once
#include <iostream>
#include <cstddef>		// size_t


//_> '^' is xor
void xorSwap(int* A, int* B)
{
	if (A != B)
	{
		*(A) ^= *(B);
		*(B) ^= *(A);
		*(A) ^= *(B);
	}
}

//_> swapping two integer values, ! no overflow checking is done in the function !
void Swap(int* A, int* B)
{
	if (A != B)
	{
		*(A) += *(B);
		*(B) = *(A)-*(B);
		*(A) -= *(B);

	}
	else
		return;	//or throw
}

//_>finding the number of digits of an integer
size_t GetDigitNumber(int number)
{
	if (number == 0)
		return 0;

	size_t digitCount = 0;

	while (number != 0)
	{
		digitCount++;
		number /= 10;
	}

	return digitCount;
}

int Abs(int num)
{
	return (num > 0) ? num : -num;
}

//_>raising a number to a given power, ! only non-negative powers
int Pow(int base, int power)
{
	if (power < 0)
		return -1;

	// trivial case
	if (power == 0)
		return 1;

	int result = 1;
	for (int i = 1; i <= power; i++) 
	{
		result *= base;
	}

	return result;
}


int PowRecursive(int num, int power)
{
	int res = 1;
	
	if (num == 1)
		return 1;

	if (power == 0)
		return 1;
	else
		res = num * MyPow(num, power - 1);

	return res;
}


//_> ?! not working with negative numbers !
long long DecimalToBinary(int decimal_number)
{
	long long result_in_binary = 0;
	unsigned int counter_for_power = 0;

	while (decimal_number != 0)
	{
		int remainder = decimal_number % 2;
		result_in_binary += remainder * Power(10, counter_for_power++);
		decimal_number /= 2;
	}

	return result_in_binary;
}

//_> ?! not working with negative numbers !
int BinaryToDecimal(long long binary_number)
{
	int result_in_decimal = 0;
	unsigned int counter_for_power = 0;

	while (binary_number != 0)
	{
		int remainder = binary_number % 2;
		result_in_decimal += remainder * Power(2, counter_for_power++);
		binary_number /= 10;
	}

	return result_in_decimal;
}


bool IsLeap(const int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

bool IsLeapV2(const int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else
		return true;
}

int ReverseInt(int number)
{
	int reversedNumber = 0;

	while (number != 0)
	{
		int remainder = number % 10;
		reversedNumber = (reversedNumber * 10) + remainder;
		number /= 10;
	}

	return reversedNumber;
}

//_> ?! not working with negative numbers !
int Factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;

	return fact;
}
