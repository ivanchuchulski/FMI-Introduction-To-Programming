/*
	yearInput format : "2016 y"
	=> len(yearInput) - 2 = number of digits

	//'0' ascii code : 48;
*/

#include <iostream>

int strLen(char* pInput) {

	char* pLink = pInput;

	while (*(pLink) != '\0') {
		pLink++;
	}
	
	return (pLink - pInput);
}

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
int convertSymToNum(char sym) {

	//switch variant
/*	switch (sym) {
		case '0' :
			return 0;
//			break;
		case '1':
			return 1;
		case '2':
			return 2;
		...

		default:
			std::cout << "Not a number!\n";
			return 0;
			break;
	}
*/

	//loop variant
/*	for (char i = '0'; i <= '9'; i++) {
		if (sym == i) {
			return (i - '0');
		}
	}
*/

	//if variant
	if (sym >= '0' || sym <= '9') {
		return (sym - '0');
	}

}

bool findLeapYear_hardcode(char yearInput[]) {
	int yearAsNumber = 0;

	int thous = 1000;
	int hundreds = 100;
	int tens = 10;
	int ones = 1;

	//handling empty string case
	if (yearInput == '\0') {
		return false;
	}

	thous *= convertSymToNum(yearInput[0]);
	hundreds *= convertSymToNum(yearInput[1]);
	tens *= convertSymToNum(yearInput[2]);
	ones *= convertSymToNum(yearInput[3]);

	std::cout << "th : " << thous
		<< ", hun : " << hundreds << ", tens : " << tens << ", ones : " << ones << std::endl;

	yearAsNumber = thous + hundreds + tens + ones;
	std::cout << "num : " << yearAsNumber << std::endl;

	//check for leap year
	if (yearAsNumber % 4 == 0)
		return true;
	else
		return false;

}

bool findLeapYear(char yearInput[]) {

	const int notDigit = 2;
	int yearAsNumber = 0;

	//handling empty string case
	if (yearInput == '\0') {
		return false;
	}

//	std::cout << "len : " << strlen(yearInput) << std::endl;
	int digitNum = (strlen(yearInput) - notDigit);
	int powerOfTen = digitNum - 1;
	
	//loop to calculate yearAsNumber
	for (int i = 0; i < digitNum; i++) {
		yearAsNumber += (convertSymToNum(yearInput[i]) * powerFunc(10, (powerOfTen)));
		powerOfTen--;
	}

	std::cout << "year : " << yearAsNumber << std::endl;

	//check for leap year
	if (yearAsNumber % 4 == 0)
		return true;
	else
		return false;

}

int main() {


	char yearAsText[] = "7 g";

	std::cout << findLeapYear_hardcode(yearAsText) << std::endl;

	std::cout << findLeapYear(yearAsText) << std::endl;

	std::cout << std::endl;
	system("pause");
	return 0;
}