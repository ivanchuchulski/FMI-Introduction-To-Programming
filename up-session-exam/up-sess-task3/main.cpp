/*	Write a function that returns the product of the second digit and k-th digit of a passed number
counting begins from 1 from left->right of the number
*/

/*ToDO - maybe handle negative numbers case
	-123; 1 -> returns -2 * -1 = 2 
*/

#include <iostream>

//power raising function for integer numbers
int powerFunc(int num, int power) {
	int result = 1;
	
	//handling zero case
	if (power == 0)
		return 1;

	//looping to calculate the power (product)
	for (int i = 1; i <= power; i++) {
		result = result * num;
	}

	return result;

}

//calculating digit count
int findDigitCount(int num) {
	int counter = 0;

	//handling zero case
	if (num == 0)
		return 1;

	//incrementing counter and dividing number
	while (num != 0) {
		counter++;
		num /= 10;
	}

	return counter;
}

//desired function
int productFunc(int num, int kPosition) {
	int secondDigit;
	int kDigit;
	int digitCount = findDigitCount(num);
	int result = 1;

	std::cout << "digitCount : " << digitCount << std::endl;

	if (digitCount == 0 || digitCount == 1) {
		std::cout << "Either empty input, zero or 1 digit!" << std::endl;
		return -1;
	}
	else if (kPosition <= 0 || kPosition > digitCount) {
		std::cout << "K-th digit does not exist!" << std::endl;
		return -1;
	}


	secondDigit = (num / powerFunc(10, (digitCount - 2))) % 10;
	kDigit = (num / powerFunc(10, (digitCount - kPosition))) % 10;
	result = secondDigit * kDigit;

	//checks
	std::cout << "second : " << secondDigit << std::endl;
	std::cout << "k-th : " << kDigit << std::endl;

	return result;
}

int main() {

	int userInput;
	int kDigitPosition;

	std::cout << "Enter number : ";
	std::cin >> userInput;
	std::cout << "Enter k-position of digit : ";
	std::cin >> kDigitPosition;

	int finalResult = productFunc(userInput, kDigitPosition);

	std::cout << "Final result : " << finalResult << std::endl;


	std::cout << std::endl;
	system("pause");
	return 0;
}