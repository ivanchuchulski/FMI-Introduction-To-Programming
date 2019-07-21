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

//search function, counters are passed by reference (& operator)
void searchInput(char *input, int k, int &openingCount, int &closingCount, bool &closure) {
	//bottom of recursion; ending the search
	if (input[k] == '\0') {
		return;
	}
	//check for a closing bracket
	if (input[k] == ')') {
		closingCount++;
		if (openingCount == 0 || closingCount > openingCount) {
			//the first bracket is closing and there are no opening before it
//			cout << "Not closed" << endl;
			closure = false;
			return;
		}
		//else {
		//	closingCount++;
		//}
	}
	//check for an opening bracket
	if (input[k] == '(') {
		openingCount++;
	}

	//checks
/*	cout << "input[" << k << "]=" << input[k] << endl;
	cout << "opening : " << openingCount << endl;
	cout << "closing : " << closingCount << endl;
	cout << endl;*/

	//recursivness
	k++;
	searchInput(input, k, openingCount, closingCount, closure);
}

int main() {

	char input[101];
	int startIndex = 0;
	int openingCount = 0;
	int closingCount = 0;
	bool closed = true;

	cout << "Input[max 100] : ";
	cin.getline(input,101);

	//handling empty string
	if (input[startIndex] == '\0') {
		//the emptystring
		cout << "Empty string" << endl;
//		system("pause");
		return 0;
	}

	searchInput(input, startIndex, openingCount, closingCount, closed);

	if (closed == false) {
		cout << "Incorrect, not closed" << endl;
//		system("pause");
		return 0;
	}
	//determining not closed, incorrect, correct string
	if ((openingCount == closingCount) && (openingCount > 0) && (closingCount > 0)) {
//		cout << "opening : " << openingCount << endl;
//		cout << "closing : " << closingCount << endl;
		cout << "Correct" << endl;
	}
	else if ((openingCount == 0) && (closingCount == 0)) {
		cout << "No brackets" << endl;
	}
	else {
//		cout << "opening : " << openingCount << endl;
//		cout << "closing : " << closingCount << endl;
		cout << "Incorrect" << endl;
	}
//	system("pause");
	return 0;
}