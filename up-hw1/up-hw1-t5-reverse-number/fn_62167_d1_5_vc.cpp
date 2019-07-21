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
#include <iostream>
#include <cmath>
using namespace std;
int find_Num_Digits(long long number) {
	if (number == 0) {
		return 1;
	}
	else {
		return ((int)log10((double)abs(number)) + 1);
	}
}
int main() {
	long long input;
	long long limit = 4294967295;
	cout << "Your input : ";
	cin >> input;
	if (input >= limit) {
		cout << "Wrong input" << endl;
		return 0;
	}
	int digitNumber = find_Num_Digits(input);
	int lastDigit = input % 10;
	int firstDigit = input / pow(10, (digitNumber - 1));
	long long swappedInput = input + (lastDigit - firstDigit) * pow(10, (digitNumber - 1)) + firstDigit - lastDigit;
	cout << "Swapped input : " << swappedInput << endl;
	return 0;
}