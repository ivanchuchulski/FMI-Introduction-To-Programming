/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 3
* @compiler VC
*
*/

/* Program to find the most frequent digit in a given number, but inputted as a string*/

#include <iostream>

using std::cout;
using std::cin;


size_t StrLen(const char* src)
{
	if (src == nullptr)
		return 0;

	const char* reader = src;

	while (*reader != '\0')
		reader++;

	return reader - src;
}

int StrCompare(const char* str1, const char* str2)
{
	char ch1, ch2;
	int difference;

	do
	{
		ch1 = *str1++;
		ch2 = *str2++;

		difference = ch1 - ch2;
	} while ((difference == 0) && (ch1 != '\0'));

	return difference;
}

int ToInteger(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	return 0;
}

// algorithm is O(length(input))
void FindDigitRepetition_original(const char* input, int* digit_counter) 
{
	int counter = 0;
	for (char j = '0'; j <= '9'; j++) 
	{
		for (int i = 0; input[i] != '\0'; i++) 
		{
			if (input[i] == j)
				counter++;
		}

		digit_counter[ToInteger(j)] = counter;

		counter = 0;
	}
}

void FindDigitRepetition(const char* input, size_t leng, int* digit_counter) 
{
	for (int i = 0; i < len; i++) 
	{
		digit_counter[ToInteger(input[i])]++;
	}
}



//determine the most frequent
void DetermineMostFrequent(int *input) 
{
	int maxFrequent = 0;
	int position = 0;

	//find one maximal
	for (int i = 0; i < 11; i++) 
	{
		if (input[i] >= maxFrequent) 
		{
			maxFrequent = input[i];
			position = i;
		}
	}

	//check if there are any other maxial
	for (int j = 0; j < 11; j++) 
	{
		if (maxFrequent == input[j] && j != position) 
		{
			cout << "{" << j << "}->" << input[j] << " times\n";
		}
	}

	cout << "{" << position << "}->" << maxFrequent << " times\n";
}

int main() {

	char input[30];
	char upper_limit[11] = "4294967296";			// len is 10
	char lower_limit[12] = "-4294967296";			// len is 11
 	int digit_counter[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	cout << "Enter a number: ";
	cin >> input;

	bool valid_input = false;

	size_t input_len = StrLen(input);
	size_t upper_len = StrLen(upper_limit);
	size_t lower_len = StrLen(lower_limit);

	int diff_to_upper = StrCompare(input, upper_limit);
	int diff_to_lower = StrCompare(input, lower_limit);


	bool negative_input = (input[0] == '-') ? true : false;

	switch (negative_input)
	{
		case true :
			if (input_len > lower_len)
			{
				cout << "error : input is incorrect : " << input << " < " << lower_limit << '\n';
				valid_input = false;
			}
			else if (input_len == lower_len)
			{
				if (diff_to_lower > 0)
				{
					cout << "error : input has the same length, but : " << input << " < " << lower_limit << '\n';
					valid_input = false;
				}
				else
					valid_input = true;

				// valid_input = (diff_to_lower > 0) ? true : false;
			}
			else 
			{
				valid_input = true;
			}

			break;

		case false : 
			if (input_len > upper_len) 
			{
				cout << "error : input is incorrect : " << input << " > " << upper_limit <<  '\n';
				valid_input =  false;
			}
			else if (input_len == upper_len)
			{
				if (diff_to_upper > 0)
				{
					cout << "error : input has the same length, but : " << input << " > " << upper_limit << '\n';
					valid_input = false;
				}
				else
					valid_input = true;

				// valid_input = (diff_to_upper > 0) ? true : false;
			}
			else
			{
				valid_input = true;
			}

			break;
	}

	if (!valid_input) 
	{
		cout << "-1\n";
		return 0;
	}

	FindDigitRepetition(input, input_len, digit_counter);

	DetermineMostFrequent(digit_counter);

	//checks
	/*	for (int i = 0; i < 10; i++) {
		cout << i << ":" << digit_counter[i] << " times \n";
	}
	cout << "diff_to_upper" << diff_to_upper << '\n';
	cout << "diff_to_lower" << diff_to_lower << '\n';*/

	return 0;
}