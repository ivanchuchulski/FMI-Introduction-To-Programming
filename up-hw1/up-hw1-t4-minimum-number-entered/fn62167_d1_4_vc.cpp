/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 4
* @compiler VC
*
*/

// the task prohibited the use of if-else statements
#include <iostream>

using std::cout;
using std::cin;

void InputMessege() 
{
	cout << "Enter a natural number : ";
}

int main() {

	int input;
	int minimal;
	bool gate = true;

	InputMessege();
	cin >> input;

	//check for correct input
	(input <= 0) ? gate = false : minimal = input;

	switch (gate) 
	{
		case false : 
			cout << "Wrong input\n";
			return 0;
			
		case true :
			break;
	}

	//loop to determine the minimal element
	while (input > 0) 
	{
		minimal = (minimal < input) ? minimal : input;
		InputMessege();
		cin >> input;
	}

	cout << "Minimal is : " << minimal << '\n';

	return 0;
}