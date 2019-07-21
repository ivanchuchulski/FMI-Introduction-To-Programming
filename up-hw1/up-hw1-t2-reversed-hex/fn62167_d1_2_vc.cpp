/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::hex;
using std::floor;
using std::log;
using std::memset;

int ReverseNum(int number)
{
	int reversedNumber = 0;
	while (number != 0)
	{
		reversedNumber = (reversedNumber * 10) + (number % 10);
		number = number / 10;
	}

	return reversedNumber;
}


void ToHex(int number)
{
	char* output;
	int remainder = 0;
	int number_of_hex_digits = 1 + (floor)(static_cast<int>(log(number) / log(16)));

	output = new char[number_of_hex_digits + 1];
	memset(output, '\0', number_of_hex_digits + 1);

	int i = number_of_hex_digits - 1; //used to first write to output from the back
	while (number > 0)
	{
		remainder = number % 16;
		
		if (remainder <= 9)
		{
			output[i] = (remainder + '0');
		}
		else
		{
			char letter = '\0';
			switch (remainder)
			{
				case 10 : 
					letter = 'A';
					break;
				case 11:
					letter = 'B';
					break;
				case 12:
					letter = 'C';
					break;
				case 13:
					letter = 'D';
					break;
				case 14:
					letter = 'E';
					break;
				case 15:
					letter = 'F';
					break;
			}

			output[i] = letter;
		}

		i--;
		number /= 16;
	}

	for (int i = 0; i < number_of_hex_digits; i++)
	{
		cout << output[i];
	}

	delete[] output;
}


int main() {

	int input;

	cout << "Enter a positive ( > 0 ) integer in decimal : ";
	cin >> input;

	//check for correct input
	if (input <= 0)
	{
		cout << "Wrong input\n";
		return 0;
	}

	//reversing the input
	int reversedInput = ReverseNum(input);

	//my original solution using library function std::hex
	//cout << "The reversed in hexadecimal : " << hex << reversedInput << '\n';

//	cout << (std::floor)(std::log(255) / std::log(16)) << '\n';

	ToHex(reversedInput);

	return 0;
}