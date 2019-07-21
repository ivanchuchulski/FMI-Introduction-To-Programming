/**
*
* Solution to homework task 09
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* 2017/2018 academic year
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <cstddef>		//for size_t definition


size_t StrLen(const char* src)
{
	if (src == nullptr)
		return 0;

	const char* ptr = src;
	while (*ptr != '\0')
		ptr++;

	return ptr - src;
}

int Power(int base, int power)
{
	if (power < 0)
		return -1;

	if (power == 0)
		return 1;

	int result = 1;
	for (int i = 1; i <= power; ++i)
	{
		result *= base;
	}

	return result;
}

int ToInt(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	else
		return 0;
}

bool IsLeapYear(const int year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	else if (year % 100 != 0)
	{
		return true;
	}
	else if (year % 400 != 0)		
	{
		return false;
	}
	else
		return true;
}

void ErrorMessage()
{
	std::cout << "Your input is incorrect\n";
}

void DisplayWeeks(unsigned short _date, unsigned short _month, unsigned long _year, bool _is_leap)
{
	/*	regular years = 365 days, 52 * 7 + 1 days
		leap years = 366 days, 52 * 7 + 1 + 1;
	*/
	const unsigned short date_initial = 1;
	const unsigned short month_initial = 1;
	const unsigned int year_initial = 2000;

	unsigned short leap_years_count = 0;

	if (_is_leap)
		leap_years_count++;

	for (unsigned long i = year_initial; i < _year; ++i)
	{
		if (IsLeapYear(i))
			leap_years_count++;
	}

	unsigned long weeks = 52 * (_year - year_initial);
	unsigned int additional_days = _year - year_initial + leap_years_count;		//each leap year adds a day

	// ToDo -> to4no do vavedena data kak da se iz4islqt sedmicite


}


//_> validation of the date
void CheckValidDate(const char* input)
{
	if (input == nullptr) {
		ErrorMessage();
		return;
	}


	const size_t format_length = 10;
	size_t len = StrLen(input);

	if (len != format_length)		//checking for correct format length DD.MM.YYYY
		ErrorMessage();

	unsigned int _date = 0;
	unsigned int _month = 0;
	unsigned long _year = 0;
	unsigned int power_counter = 2;

	for (unsigned int i = 0; i < format_length - 8; ++i)
	{
		//checking if the element is a number
		if (!(input[i] >= '0' && input[i] <= '9'))
		{
			ErrorMessage();
			return;
		}
		_date += ToInt(input[i]) * Power(10, --power_counter);
	}

	power_counter = 2;
	for (unsigned int j = format_length - 7; j < format_length - 5; ++j)
	{
		if (!(input[j] >= '0' && input[j] <= '9'))
		{
			ErrorMessage();
			return;
		}
		_month += ToInt(input[j]) * Power(10, --power_counter);
	}

	power_counter = 4;
	for (unsigned int k = format_length - 4; k < format_length; ++k)
	{
		if (!(input[k] >= '0' && input[k] <= '9'))
		{
			ErrorMessage();
			return;
		}
		_year += ToInt(input[k]) * Power(10, --power_counter);
	}


	if (_date > 31 || _date < 1)
	{
		ErrorMessage();
		return;
	}

	if (_month > 12 || _month < 1)
	{
		ErrorMessage();
		return;
	}

	// ferbruary case
	bool is_leap = IsLeapYear(_year);
	if (_month == 2 && _date == 29 && IsLeapYear(_year) == false)
	{
		ErrorMessage();
		return;
	}

	switch (_month)
	{
		//April, June, September and November have 30 days
		case 4: case 6: case 9: case 11:
		{
			if (_date == 31)
			{
				ErrorMessage();
				return;
			}
		}
		default:
			break;
	}

	DisplayWeeks(_date, _month, _year, is_leap);
}




int main() {


	{

		char sample[]{ "30.06.2018" };



	}

	std::cin.get();
	return 0;
}



















