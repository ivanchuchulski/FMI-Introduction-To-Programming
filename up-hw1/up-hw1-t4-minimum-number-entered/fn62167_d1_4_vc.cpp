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
#include <iostream>
using namespace std;
void inputMessege() {
	cout << "Enter a natural number : ";
}
int main() {
	int input;
	int minimal;
	bool gate = true;
	inputMessege();
	cin >> input;
	//check for correct input
	(input <= 0) ? gate = false : minimal = input;
	switch (gate) {
		case false: {
			cout << "Wrong input" << endl;
			system("pause");
			return 0;
		}
		default:
			break;
	}
	//loop to determine the minimal element
	while (input > 0) {
		minimal = ((minimal < input) ? minimal : input);
		inputMessege();
		cin >> input;
	}
	cout << "Minimal is : " << minimal << endl;
	system("pause");
	return 0;
}