/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 6
* @compiler VC
*
*/

#include <iostream>

using std::cout;
using std::cin;

void drawTriangle(int height, char symbol)
{
	for (int i = 0; i < height; i++)
	{
		//loop for the beginning empty spaces 
		for (int j = 0; j <= height - 2 - i; j++)
		{
			cout << " ";
		}

		//loop for dispalying the characters and spaces between them
		for (int s = 0; s <= i; s++)
		{
			cout << symbol;
			if (s != i)
			{
				cout << " ";
			}
		}

		cout << "\n";
	}
}

int main() {

	const int MIN_HEIGHT = 0;
	const int MAX_HEIGHT = 22;

	int height;
	char symbol;

	cout << "Enter height of triangle : ";
	cin >> height;

	if (height < MIN_HEIGHT || height > MAX_HEIGHT)
	{
		cout << "error : wrong input, triangle height must be within [0, 22]\n";
		return 0;
	}

	cout << "Enter triangle draw symbol : ";
	cin >> symbol;

	drawTriangle(height, symbol);

	return 0;
}