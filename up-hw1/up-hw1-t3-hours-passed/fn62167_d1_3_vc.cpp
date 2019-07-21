/**
*
* Solution to homework task
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

#include <iostream>

using std::cout;
using std::cin;

int main() {

	int input;

	cout << "Enter seconds : ";
	cin >> input;

	if (input < 0 || input > 86400) 	//second in a day is 24h * 3600s
	{
		cout << "Wrong input\n";
		return 0;
	}

	int hoursPassed = (input / 3600);
	int minutesPassed = ((input / 60) % 60);

	if (hoursPassed <= 9) 
	{
		if (minutesPassed <= 9) 
		{
			cout << "The time is 0" << hoursPassed << " : 0" << minutesPassed << '\n';
		}
		else 
		{
			cout << "The time is 0" << hoursPassed << " : " << minutesPassed << '\n';
		}
	}
	else 
	{
		if (minutesPassed <= 9) 
		{
			cout << "The time is " << hoursPassed << " : 0" << minutesPassed << '\n';
		}
		else 
		{
			cout << "The time is " << hoursPassed << " : " << minutesPassed << '\n';
		}
	}


	return 0;
}