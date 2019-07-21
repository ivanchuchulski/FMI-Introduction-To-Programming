/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 1
* @compiler VC
*
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void GetDifference(int x, int y) 
{
	int differenceXtoY = y - x;

	if (differenceXtoY > 0) 
		cout << "Increasing sequence\n";
	
	else if (differenceXtoY < 0) 
		cout << "Decreasing sequence\n";

	else 
		cout << "The sequence is undefined\n";
}

void InputMessege() 
{
	cout << "Enter a natural number : ";
}

int main() {

	int firstTerm;
	int secondTerm;

	InputMessege();
	cin >> firstTerm;

	if (firstTerm <= 0) 
	{
		cout << "Wrong input\n";
		return 0;
	}

	InputMessege();
	cin >> secondTerm;

	if (secondTerm <= 0) 
	{
		cout << "Wrong input\n";
		return 0;
	}

	else if (secondTerm == firstTerm) 
	{
		GetDifference(firstTerm, secondTerm);
		return 0;
	}
	else 
	{
		while (secondTerm > 0) 
		{
			int nextTerm;

			InputMessege();
			cin >> nextTerm;

			if (nextTerm <= 0) 
			{
				//wrong input, display what the sequece was until then
				GetDifference(firstTerm, secondTerm);
				return 0;
			}
			else if (nextTerm == secondTerm) 
			{
				//the sequence became undefined
				GetDifference(secondTerm, nextTerm);
			}
			else if ((nextTerm > secondTerm && secondTerm < firstTerm) || (nextTerm < secondTerm && secondTerm > firstTerm)) 
			{
				//nextTerm broke the pattern of the previous terms
				cout << "The sequence is undefined\n" << endl;
				return 0;
			}
			else 
			{
				firstTerm = secondTerm;
				secondTerm = nextTerm;
			}
		}
	}


	return 0;
}