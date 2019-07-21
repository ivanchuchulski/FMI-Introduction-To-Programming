#include <iostream>
#include <vector>
#include <string>


const std::vector<std::string> Ones{ "", "one", "two", "three", "four", "five", 
										"six", "seven", "eight", "nine" };

const std::vector<std::string> Teens{ "ten", "eleven", "twelve", "thirteen", "fourteen",  "fifteen", 
										"sixteen", "seventeen", "eighteen", "nineteen" };

const std::vector<std::string> Tens{ "", "", "twenty","thirty", "forty",  "fifty", 
										"sixty", "seventy", "eighty", "ninety" };


std::string NumberToText(long long number)
{
	const long int one_thousand = 100000;
	const long int one_billion = 1000000000;

	if (number < 10)
	{
		return std::string(Ones[number]);
	}
	else if (number < 20)
	{
		return std::string(Teens[number - 10]);
	}
	else if (number < 100)
	{
		if (number % 10 == 0)		// true if the last digit is zero
			return std::string(Tens[number / 10] + "");
		else
			return std::string(Tens[number / 10] + " " + NumberToText(number % 10));
	}
	else if (number < 1000)
	{
		return NumberToText(number / 100) + " hundred" + ( (number % 100 == 0) ? ("") : (" " + NumberToText(number % 100)) ) ;
	}

	else if (number < one_thousand)
	{
		return NumberToText(number / 1000) + " thousand" + ( (number % 1000 == 0) ? ("") : (" " + NumberToText(number % 1000)) );
	}

	else if (number < one_billion)
	{
		return NumberToText(number / 100000) + " million" + ( (number % 1000 == 0) ? ("") : (" " + NumberToText(number % 1000)) );
	}
	else
	{
		return std::string("error");
	}
}


int main() 
{
	long long number;

	std::cin >> number;

	if (number < 0 || number > 999999999)
	{
		std::cout << "Error : numbers should be in range [0, 999 999 999] \n";
	}

	std::cout << NumberToText(947) << '\n';

	return 0;
}