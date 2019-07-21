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
using namespace std;
void drawTriangle (short height, char symbol)
{
	//loop for drawing the height of the triangle
	for (int i = 0; i <= height - 1; i++) 
	{
		//loop for the empty spaces 
		for (int j = 0; j <= height - i - 2; j++) 
		{
			cout << " ";
		}
		//loop for dispalying the characters
		for (int s = 0; s <= i; s++) 
		{
			cout << symbol;
			if (s != i) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
int main() {
	short height;
	cout << "Enter height of triangle : ";
	cin >> height;
	if (height <= 0) {
		cout << "Wrong input, triangle cant have negative height" << endl;
		return 0;
	}
	else if (height > 22) {
		cout << "Wrong input, triangle too high" << endl;
		return 0;
	}
	char symbol;
	cout << "Enter a symbol : ";
	cin >> symbol;
	drawTriangle (height, symbol);
	return 0;
}