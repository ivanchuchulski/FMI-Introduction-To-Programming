/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 5
* @compiler VC
*
*/

//the task prohibited the use of loops, the program swaps the first and last digits of a number
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::abs;
using std::log10;

using int64 = long long;

int GetDigitCount(long long number) 
{
	if (number == 0) 
		return 1;
	 
	return 1 + (int)log10((double)abs(number));
}

int main() {

	int64 input;
	int64 limit = 4294967295;	//basicly the upper bound of a 32-bit unsigned integer

	cout << "input a number : ";
	cin >> input;

	if (input >= limit) 
	{
		cout << "error : wrong input\n";
		return 0;
	}

	int digit_count = GetDigitCount(input);

	if (digit_count < 2)
	{
		cout << "Swapped input : " << input << '\n';
	}

	int last_digit = input % 10;
	int first_digit = input / pow(10, (digit_count - 1));

	int64 swapped_input = input + (last_digit - first_digit) * pow(10, (digit_count - 1)) + first_digit - last_digit;

	cout << "Swapped input : " << swapped_input << '\n';

	return 0;
}