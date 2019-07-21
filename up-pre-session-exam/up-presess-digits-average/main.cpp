/* Write a funftion that finds the arithmetic mean(rounded down to a integer number) of the digits 
of a given positive integer. You have to use one void funtion, that does NOT call other functions.
->	we need to use unsigned int;
->	hard-code variant
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void findDigitAverage(unsigned int number) {
	int aritMean = 0;
	int sum = 0;
	int counter = 0;

	cout << number;
	//handling zero case
	if (number == 0) {
		cout << " -> Arithmetical Mean = 0; its zero" << endl;
		return;
	}
	//algorithm
	while (number != 0) {
		sum = sum + (number % 10);
		counter++;
		number = number / 10;
	}

	//calculating mean, bec. its integer, it will autocut the fraction part
	aritMean = (sum / counter);
	cout << " -> Arithmetical Mean of the digits : " << aritMean << endl;
}
int main() {
	unsigned int firstNum = 0;
	unsigned int secondNum = 15;
	unsigned int thirdNum = 113;
 
	findDigitAverage(firstNum);
	findDigitAverage(secondNum);
	findDigitAverage(thirdNum);

	system("pause");
	return 0;
}