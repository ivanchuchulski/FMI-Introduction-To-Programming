//basic algorithms for numbers and strings

#ifndef ALGS_H
#define ALGS_H

unsigned GetDigitCount(int number)
{
	if (number == 0)
		return 1;

	int digit_count = 0;

	while (number != 0)
	{
		digit_count++;
		number /= 10;
	}

	return digit_count;
}

int ReverseInteger(int number)
{
	if (number == 0)
		return 0;

	int reversed_num = 0;

	while (number != 0)
	{
		int remainder = number % 10;
		reversed_num = reversed_num * 10 + remainder;
		number /= 10;
	}

	return reversed_num;
}

// works only when power >= 0
int Power(int base, int power)
{
	if (power < 0)
	{
	//	std::cerr << "Error : function works only for powers >= 0\n";
		return -1;
	}

	if (power == 0)
		return 1;

	int result = 1;

	for (int i = 1; i <= power; i++)
		result *= base;

	return result;
}

int Factorial(int num)
{
	// error
	if (num < 0)
		return -1;

	if (num == 0 || num == 1)
		return 1;

	int fact = 1;

	for (int i = 1; i <= num; i++)
		fact *= i;

	return fact;
}


// c-style strings algorithms

int ToInteger(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	return 0;
}

char ToLower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch + ('a' - 'A');

	return ch;
}

char ToUpper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - ('a' - 'A');

	return ch;
}


size_t StrLen(const char* src)
{
	if (src == nullptr)
		return 0;

	const char* reader = src;

	while (*reader != '\0')
		reader++;

	return reader - src;
}

char* StrCopy(char* dest, const char* src)
{
	size_t index = 0;

	do 
	{
		dest[index] = src[index];

	} while (src[index++] != '\0');

	return dest;
}

char* StrCat(char* dest, const char* src)
{
	char* p_dest = dest;

	while (*p_dest != '\0')
		p_dest++;

	StrCopy(p_dest, src);

	return dest;
}

int StrCompare(const char* str1, const char* str2)
{
	char ch1, ch2;
	int difference;

	do
	{
		ch1 = *str1++;
		ch2 = *str2++;

		difference = ch1 - ch2;
	} while ((difference == 0) && (ch1 != '\0'));

	return difference;
}

// num-pos := 1234, digit positions are counted from left to right
int KthDigit(int num, int k)
{
	if (k < 1)
		return -1;

	unsigned digit_count = GetDigitCount(num);

	if (digit_count < k)
		return -1;

	return ((num / Power(10, digit_count - k)) % 10);
}

// kind of primitive version of substr, searching for word in symbols
bool DoExist(char* symbols, char* word)
{
	if (symbols == nullptr || word == nullptr)		//better throw
		return false;

	size_t symb_len = StrLen(symbols);
	size_t word_len = StrLen(word);

	//same length case
	if (symb_len == word_len)
	{
		for (size_t i = 0; i < symb_len; i++)
		{
			if (symbols[i] != word[i])
				return false;
		}

		return true;
	}

	//otherwise
	bool is_substr = false;

	for (size_t i = 0; i < (symb_len - word_len + 1); i++)
	{
		if (symbols[i] == word[0])
		{
			is_substr = true;

			for (size_t j = 1; j < word_len; j++)
			{
				if (symbols[++i] != word[j])
					return false;
			}

			if (is_substr)
				return true;
			else
				is_substr = false;		//for next iteration
		}
	}

	//if the loop has finished, no matches had been found
	return false;
}



#endif ALGS_H