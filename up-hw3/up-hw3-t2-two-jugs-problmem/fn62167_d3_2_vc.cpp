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
using std::cout;
using std::cin;
using std::endl;

int calculateMax(int a, int b) {
	return (a > b) ? (a) : (b);
}

int calculateMin(int a, int b) {
	return (a < b) ? (a) : (b);
}

int greatestCommonDivisor(int a, int b) {
	if (a == b) {
		return a;
	}
	else if (a > b) {
		greatestCommonDivisor(a - b, b);
	}
	else if (a < b) {
		greatestCommonDivisor(a, b - a);
	}
}

void calculatingSteps(int firstVolume, int secondVolume, int kLiters, int source, int dest, int &counter) {
	int sourceLiters = source;
	int destLiters = dest;
	int water = calculateMin(sourceLiters, (secondVolume - destLiters));

		//filling
		destLiters = destLiters + water;
		sourceLiters = sourceLiters - water;
		counter++;

		//bottom of recursion
		if (destLiters == kLiters || sourceLiters == kLiters) {
			return;
		}

		if (sourceLiters == 0) {
			//filling the source if it becomes empty
			sourceLiters = firstVolume;
			counter++;
		}

		if (destLiters == secondVolume) {
			//emptying the destination if it becomes full
			destLiters = 0;
			counter++;
		}

		//recursion
		calculatingSteps(firstVolume, secondVolume, kLiters, sourceLiters, destLiters, counter);
}


int main() {
	const int lowerLimit = 1;
	const int upperLimit = 20;
	const char notPossible[] = {'-', '1', '\0'};
	int n;		//first legen capacity
	int m;		//second legen capacity
	int k;		//amount of water

	cout << "Enter n :";
	cin >> n;
	cout << "Enter m : ";
	cin >> m;
	cout << "Enter k liters : ";
	cin >> k;

	//handling input restrictions
	if (n < lowerLimit || n > upperLimit || m < lowerLimit || m > upperLimit) {
		cout << "Wrong input, incorrect capacity" << endl;
		system("pause");
		return 0;
	}

	//checks
/*	if (n == m) {
		cout << "two legens with same capacity!" << endl;
	}	
	cout << "max : " << calculateMax(n, m) << endl;
	cout << "min: " << calculateMin(n, m) << endl;
	cout << "gcd : " << greatestCommonDivisor(n, m) << endl;*/

	//too much water case
	if (k > calculateMax(n, m)) {
//		cout << "too much water" << endl;
		cout << notPossible << endl;
//		system("pause");
		return 0;
	}

	if ((k == n) || (k == m)) {
		//k litres is filled with 1 step into one of the legens
		cout << "1" << endl;
//		system("pause");
		return 0;
	}

	//check if diophantine equation has solution
	if ((k % greatestCommonDivisor(n, m)) != 0) {
//		cout << "impossible, blame Diophantus" << endl;
		cout << notPossible << endl;
//		system("pause");
		return 0;
	}

	int counter1 = 1;
	int counter2 = 1;
	int emptyState = 0;

	calculatingSteps(n, m, k, n, emptyState, counter1);
	calculatingSteps(m, n, k, m, emptyState, counter2);

//	cout << "counter1 : " << counter1 << endl;
//	cout << "counter2 : " << counter2 << endl;

	cout << "Min steps : " << calculateMin(counter1, counter2) << endl;


//	system("pause");
	return 0;
}