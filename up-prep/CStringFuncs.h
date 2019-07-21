#pragma once

#include <cstddef>		//for size_t
using std::size_t;

namespace cstr {


	//_> 'a' = 97, 'A' = 65 so subtracting them will give the difference (32) between the lower and upper registers
 	char ToUpper(char source)
	{
		if (source >= 'a' && source <= 'z')
		{
			return source - ('a' - 'A');
		}

		//otherwise : source may be already in upper
		return source;
	}

	//_>
	char ToLower(char source)
	{
		if (source >= 'A' && source <= 'Z')
		{
			return source + ('a' - 'A');
		}

		return source;
	}

	//_> ascii code of '0' = 48
	int ToInt(char source)
	{
		if (source >= '0' && source <= '9')
		{
			return (source - '0');
		}

		//otherwise
		return 0;
	}


	//_> string length
	size_t StrLen(const char* source)
	{
		//NULL check
		if (source == nullptr)
			return 0;

		const char* pRead = source;

		while (*pRead != '\0')
		{
			pRead++;
		}

		return (pRead - source);
	}

	//_> string copy, copies the terminating null
	char* StrCopy(char* destination, const char* source)
	{
		if (source == nullptr || destination == nullptr)				//	throw, or assert ...
			return nullptr;

		//check if the same address is passed
		if (destination == source)
			return nullptr;

		size_t index = 0;
		do 
		{
			destination[index] = source[index];

		} while (source[index++] != '\0'); 

		return destination;
	}

	char* StrCopyV2(char* dest, const char* src)
	{
		char* initial_dest = dest;

		do
		{
			*dest++ = *src;
		} while (*src++ != '\0');

		return initial_dest;
	}

	//_>  concatenatenation
	char* StrCat(char* dest, const char* src)
	{
		char* p_dest = dest;

		//going to the end of destination
		while (*p_dest != '\0')
			p_dest++;

		//now copying from the source
		StrCopy(p_dest, src);

		return dest;
	}


	//_> comparing two strings
	int StrCompare(const char* str1, const char* str2)
	{
		unsigned char ch1;
		unsigned char ch2;
		int difference;

		do
		{
			ch1 = (unsigned char)*(str1++);
			ch2 = (unsigned char)*(str2++);

			difference = ch1 - ch2;

		} while ((difference == 0) && (ch1 != '\0'));


		return difference;
	}







}