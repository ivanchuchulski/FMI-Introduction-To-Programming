/**
*
* Solution to second homework task
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

//get digit repetition
void getRepeats(char *input, int *digitRepeats) {
	int counter = 0;
	//comparing
	for (char j = '0'; j <= '9'; j++) {
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == j) {
				counter++;
			}
		}
		digitRepeats[int(j) - 48] = counter;
		//set the counter to zero for next iteration
		counter = 0;
	}
}

//determine the most frequent
void mostFrequent(int *input) {
	int maxFrequent = 0;
	int position = 0;
	//find one maximal
	for (int i = 0; i < 11; i++) {
		if (input[i] >= maxFrequent) {
			maxFrequent = input[i];
			position = i;
		}
	}
	//check if there are any other maxial
	for (int j = 0; j < 11; j++) {
		if (maxFrequent == input[j] && j != position) {
			cout << "{" << j << "}->" << input[j] << " times\n";
		}
	}
	cout << "{" << position << "}->" << maxFrequent << " times\n";


}

//string length
int strLength(char *input) {
	char *pLink = input;
	while (*pLink != '\0') {
		pLink++;
	}
	//returning the length
	return (pLink - input);
}

//string comparison
int comparison(char *a, char *b) {
	unsigned char a1;
	unsigned char b1;
	int difference;
	do {
		a1 = (unsigned char)*a++;
		b1 = (unsigned char)*b++;
		difference = a1 - b1;
	} while ((difference == 0) && (a1 != '\0'));

	return difference;

}

//determine gate
bool gate(char *input, int diffToUpper, int diffToLower) {
	//check if input is the limit
	if (diffToUpper == 0 || diffToLower == 0) {
		cout << "matches the limit \n";
		return true;
	}
	else {
		if (diffToLower > 0 && input[0] == '-') {
			cout << "input < lower \n";
			return false;
		}
		else {
			if (diffToUpper > 0 && input[0] != '-') {
			cout << "input > upper \n";
				return false;
			}
		}
	}
	//everything is passed, so it alright
	return true;
}

int main() {
	char input[30];
	char upperLimit[11] = "4294967296";
	char lowerLimit[12] = "-4294967296";
 	int digitRepeats[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	cout << "Enter input : ";
	cin >> input;

	bool gateOpen = false;

	int inputLen = strLength(input);
	int upperLen = strLength(upperLimit);
	int lowerLen = strLength(lowerLimit);

	int diffToUpper = comparison(input, upperLimit);
	int diffToLower = comparison(input, lowerLimit);


	//handling the input
	if (inputLen > upperLen && input[0] != '-') {
		cout << "too large \n";
		gateOpen =  false;
	}
	else if (inputLen > lowerLen) {
		cout << "too small \n";
		gateOpen = false;
	}
	else {
		cout << "check if input has the same lenght but is bigger/smaller than limit\n";
		if ((inputLen == upperLen && input[0] != '-') || inputLen == lowerLen) {
			gateOpen = gate(input, diffToUpper, diffToLower);
		}
		else {
			gateOpen = true;
		}
	}

	if (gateOpen == false) {
		cout << "-1\n";
//		system("pause");
		return 0;
	}

	getRepeats(input, digitRepeats);

	mostFrequent(digitRepeats);

	//checks
	/*	for (int i = 0; i < 10; i++) {
		cout << i << ":" << digitRepeats[i] << " times \n";
	}
	cout << "diffToUpper" << diffToUpper << '\n';
	cout << "diffToLower" << diffToLower << '\n';*/

	cout << '\n';
//	system("pause");
	return 0;
}