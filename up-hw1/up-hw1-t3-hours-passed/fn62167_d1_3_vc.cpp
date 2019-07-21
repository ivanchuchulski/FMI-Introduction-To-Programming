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
using namespace std;
int main() {
	int input;
	cout << "Enter seconds : ";
	cin >> input;
	if (input < 0 || input > 86400) {
		cout << "Wrong input" << endl;
		return 0;
	}
	int hoursPassed = (input / 3600);
	int minutesPassed = ((input / 60) % 60);
	cout << hoursPassed << endl;
	cout << minutesPassed << endl;
	if (hoursPassed <= 9) {
		if (minutesPassed <= 9) {
			cout << "The time is 0" << hoursPassed << " : 0" << minutesPassed << endl;
			return 0;
		}
		else {
			cout << "The time is 0" << hoursPassed << " : " << minutesPassed << endl;
			return 0;
		}
	}
	else {
		if (minutesPassed <= 9) {
			cout << "The time is " << hoursPassed << " : 0" << minutesPassed << endl;
			return 0;
		}
		else {
			cout << "The time is " << hoursPassed << " : " << minutesPassed << endl;
			return 0;
		}
	}
	return 0;
}