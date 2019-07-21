#pragma once

#include <iostream>
#include <cstddef>		// for size_t

double Absoulute(double arg)
{
	if (arg == 0)
		return 0;
	else 
		return (arg > 0) ? (arg) : (-arg);
}

//_> task1
double Sqrt_a(double a, double epsilon)
{
	
	if (a < 0)			// square root of a negative is not real number, but a complex number
		return -1;

	else if (a == 0)	//otherwise it could cause division by zero
		return 0;

	//initially set to a
	double x_current = a;
	double x_next = 0.0;

	while (true) 
	{
		x_next = 0.5 * (x_current + (a / x_current));

	//	std::cout << Absoulute(x_next - x_current) << " ? < ? " << epsilon << '\n';

		if (Absoulute(x_next - x_current) < epsilon)
		{
			return x_next;
		}
		else
		{
			x_current = x_next;
		}
	}


}

//---------------------------------------------------------


size_t StrLen(const char* source)
{
	if (source == nullptr)	// or maybe throw exception?
		return 0;

	const char* pRead = source;

	while (*pRead != '\0')
		pRead++;

	return pRead - source;
}

char ToUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - ('a' - 'A');

	else
		return ch;
}

char ToLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch  + ('a' - 'A');

	else
		return ch;
}

//_> task2
void Revert(char input[])
{
	//null check
	if (input == nullptr)
		return;

	int len = StrLen(input);

	for (int i = 0; i < len; ++i)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
		//	input[i] = ToUpper(input[i]);
			input[i] -= ('a' - 'A');
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
		//	input[i] = ToLower(input[i]);
			input[i] += ('a' - 'A');
		}
	}
}

//---------------------------------------------------------

int ToInt(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	else
		return 0;
}

inline bool IsInteger(const char ch)
{
	return (ch >= '0' && ch <= '9');
}

//_> task 3
bool CheckDate(char	input[])
{
	if (input == nullptr)
		return false;

	const size_t format_length = 5;
	size_t len = StrLen(input);

	if (len != format_length)		//checking for correct format length DD.MM
		return false;

	int date = 0;
	int month = 0;
	unsigned power_counter = 2;

	// making date and month, checking for correct symbols, e.g. : '-', '+', '^' would result in a false function return
	for (unsigned int i = 0; i < format_length - 3; ++i)
	{
		if (IsInteger(input[i]) == false || IsInteger(input[i + 3]) == false)
			return false;

		else
		{
			date += ToInt(input[i]) * Power(10, --power_counter);
			month += ToInt(input[i + 3]) * Power(10, power_counter);
		}
	}


	if (date > 31 || date < 1)
		return false;

	if (month > 12 || month < 1)
		return false;

	// ferbruary case
	if (month == 2 && date > 28)		//not complete due, to no provided year and possible leap year
		return false;

	switch (month)
	{
		//April, June, September and November have 30 days
		case 4 : case 6 : case 9 : case 11 :
		{
			if (date == 31)
				return false;
		}
		default :
			break;
	}

	return true;
}

//---------------------------------------------------------

unsigned NumOfDigits(int number)
{
	if (number == 0)
		return 0;

	unsigned int digit_count = 0;

	while (number != 0)
	{
		digit_count++;
		number /= 10;
	}

	return digit_count;
}

//_> task 4, num_positions := 12345
int DigitPos(long num, int k)
{
	if (k <= 0)
		return -1;

	unsigned int len = NumOfDigits(num);

	if (len < k)
		return -1;

	return ((num / Power(10, len - k)) % 10 );
}



//---------------------------------------------------------

//_> task5, NOT COMPLETE
bool DoExist(char* symbols, char* word)
{
	if (symbols == nullptr || word == nullptr)		//better throw
		return false;

	size_t symb_len = StrLen(symbols);
	size_t word_len = StrLen(word);

	if (symb_len == word_len)
	{
		bool is_substr = true;

		for (size_t i = 0; i < symb_len; i++)
		{
			if (symbols[i] != word[i])
				is_substr = false;
		}

		return is_substr;
	}

	bool is_substr = false;

	//the check in the loop covers the case, when word_len > symb_len
	for (size_t i = 0; i < (symb_len - word_len + 1) ; i++)
	{
		if (symbols[i] == word[0])
		{
			// if word is only of 1 char (len = 2), then the loop wont start, but it has 1 matching symbol
			is_substr = true;

			for (size_t j = 1; j < word_len; j++)
			{
				if (symbols[++i] != word[j])
					is_substr = false;
			}


			if (is_substr == true)
				return is_substr;

			else
				is_substr = false;		//for next iteration

		}
	}

	//if the loop has finished, no matches had been found
	return false;
}

//---------------------------------------------------------






//_> counting the rightmost digit to be first, num_positions := 4321
/*
	4 = (num / 10^3) % 10 
	3 = (num / 10^2) % 10 
	2 = (num / 10^1) % 10 
	1 = (num / 10^0) % 10 


*/
int DigitPosV2(long num, int k)
{
	if (k <= 0)
		return false;

	unsigned int len = NumOfDigits(num);

	if (len < k)
		return false;

	return ((num / Power(10, k - 1)) % 10);
}