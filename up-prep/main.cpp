#include <iostream>
#include <array>
#include <cstring>

#include "CStringFuncs.h"
#include "ArrayAlgorithms.h"
#include "poprav_may.h"
#include "SomeAlgorithms.h"
#include "primerni_2.h"
#include "september_18.h"




//_>	HH:MM
/*		1 minute = 60 s
		60 mins = 1 hour = 3600 s
		1 day = 24 hr = 86400s


		example : 3660 = 1hr 1min
				: 90060 = 1d 1hr 1min

*/
void PrintHour(int seconds)
{
	if (seconds < 0 || seconds > 86400)
		std::cerr << "Opa, wrong input\n";

	//unsigned int mins = seconds / 60;
	//unsigned int hours = mins / 60;
	//mins %= 60;

	unsigned mins = (seconds / 60) % 60;
	unsigned hours = seconds / 3600;

	std::cout << "HH " << hours << " :MM " << mins << '\n';
}

void PrintDays(long long int seconds)
{
	unsigned mins = (seconds / 60) % 60;
	unsigned hours = (seconds / 3600);
	unsigned days = (hours / 24);		// or hours / 86400

	hours %= 24;

	std::cout << "DD " << days << " :HH " << hours << " :MM " << mins << '\n';

}

int main() {

	{
		//char ch1[5];
		//char ch2[5] = "abcd";


		//char* p2 = cstr::StrCopy(ch1, ch2);

		//cstr::StrCompare("abc", "adcg");

		//IsCorrect("cba");

		//Power(7, 2);
		//LeapYear("2016 g.");

		//std::array<double, 5> myArr = { 3.0, 7.0, 6.0, 8.0, 11.0 };

		//arralg::SelectionSort(&myArr[0], myArr.size());

		//myArr.empty();

		//float n1 = 13.3f;
		//float n2 = 50.0f;
		//alg::Swap(&n1, &n2);

		//if (true)
		//	std::cout << n1 << ", " << n2 << '\n';

	//	std::cout << (alg::DecimalToBinary(3)) << '\n';
	//	std::cout << (alg::BinaryToDecimal(11)) << '\n';
	
	}
	
	{

	//	_> task1 test
		//std::cout << Sqrt_a(5.0, 0.001) << '\n';

	//	_> task2 test
		//char a[] = "aBcD";
		//Revert(a);

		//std::cout << a << std::endl;

	//	_>task3 test
		char arr[] { "21.02" };
		CheckDate(arr);

	//	std::cout << alg::IsLeap(2000) << " ?=? " << IsLeapV2(2000) << '\n';
	//	std::cout << alg::IsLeap(2200) << " ?=? " << IsLeapV2(2200) << '\n';

	//	_>task4 test
		std::cout << "DigitPos tests : \n" << DigitPos(1234, 4) << '\n';
		std::cout << DigitPos(1234, 3) << '\n';
		std::cout << DigitPos(1234, 2) << '\n';
		std::cout << DigitPos(1234, 1) << "\n\n";

		std::cout << "DigitPosV2 tests : \n" << DigitPosV2(4321, 4) << '\n';
		std::cout << DigitPosV2(4321, 3) << '\n';
		std::cout << DigitPosV2(4321, 2) << '\n';
		std::cout << DigitPosV2(4321, 1) << "\n\n";

		char source_str[]{ "abcdecccf" };
		char target_str[]{ "ccc" };
		char opa[7]{'\0'};

	//	std::cout << std::strstr(source_str, target_str) << '\n';
		std::cout << "DoExist : " << DoExist(source_str, target_str) << '\n';


		NumCheck(-12333);


	}

	//sizes and literals test
	{


	//	unsigned long long li = 123'456'789'123'456'789ull;
	//	auto a = 0xA + 2.0f;
	//	auto b = 0xE + 3.0;
	//	long double c = 34.03L;

	//	int bin = 0b101;

	//	std::cout << li << '\n';
	//	std::cout << a << '\n';
	//	std::cout << b << '\n';
	//	std::cout << c << '\n';

	//	auto d1 = 2.34e-3l;

	//	std::cout << sizeof(unsigned int) << '\n';
	//	std::cout << sizeof(std::size_t) << "\n\n";

	//	std::cout << sizeof(short int) << '\n';
	//	std::cout << sizeof(int) << '\n';
	//	std::cout << sizeof(long int) << '\n';
	//	std::cout << sizeof(long long int) << "\n\n";

	//	std::cout << sizeof(float) << '\n';
	//	std::cout << sizeof(double) << '\n';
	//	std::cout << sizeof(long double) << '\n';
	}


	{
		//const size_t len = 5;

		//char c1[len]{ "0123" };
		//char c2[len]{ "abcd" };

		//cstr::StrCopy(c2, c1);

		//
		//if (*c1 == *c2)
		//	std::puts("Opa, pravilno kolega\n");

		//PrintHour(86400);
		//PrintDays(90060);
		//std::cout << alg:: ReverseInt(-123);

		//alg::Factorial(3);
	}

	std::cin.get();
	return 0;
}