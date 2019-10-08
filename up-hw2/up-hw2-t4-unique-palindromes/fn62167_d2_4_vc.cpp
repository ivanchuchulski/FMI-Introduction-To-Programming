/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 4
* @compiler VC
*
*/

// program to find the unique substrings palindrome in a given string

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_LEN = 11;

int StrLen(char* input) 
{
	char *reader = input;

	while (*reader != '\0')
		reader++;

	return (reader - input);
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

int StrCompare(const char* str1, const char* str2) 
{	
	char c1, c2;
	int diff;

	do {
		c1 = *str1++;
		c2 = *str2++;

		diff = c1 - c2;

	} while ((diff == 0) && (c1 != '\0'));

	return diff;
}

bool IsPalindrome(char *input, const size_t length) 
{
	for (int i = 0; i < (length / 2); i++) {
		if (input[i] != input[length - i - 1]) {
			//cout << input[i] << "!=" << input[length - i - 1] << endl;
			//some character is different
			return false;
		}
	}

	return true;
}

void FindSubstrings(const char* input, const size_t length, char palindromes[][MAX_LEN], int& ref_copies) 
{
	char* word = new char[length + 1];		// creating dynamic array for substring
	std::memset(word, '\0', length + 1);	// setting all the bytes to zero
	int indx_word = 0;
	int indx_pali = 0;

	// searching the string; i is the pivot(starting point)
	for (int i = 0; i < length - 1; i++) 
	{
		word[indx_word++] = input[i];

		for (int j = i + 1; j < length; j++) 
		{
			word[indx_word++] = input[j];
			word[indx_word] = '\0';

			if (IsPalindrome(word, length)) 
			{
				// printing for debugging the pali
				// for (int m = 0; word[m] != '\0'; m++)  cout << word[m];
				// cout << endl;

				StrCopy(palindromes[indx_pali++], word);
			}
		}

		indx_word = 0;
	}

	//freeing up heap memory
	delete[] word;

	ref_copies = q;
	cout << "copies, all palindromes : " << q << endl;
}

int main() {

	char input[51];

	cout << "Input (max 50 symbols) : ";
	cin.getline(input, 51);
	
	int length_input = StrLen(input);

	//MAX_LEN word, (MAX_LEN - 1) length of a word + 1 for '\0'	11, 10
	char palindromes[MAX_LEN][MAX_LEN];
	int copyiesOccured = 0;
	int counter = 0;

	for (int i = 0; i < ::MAX_LEN; i++)
		memset(palindromes[i], 0, MAX_LEN);
	
	// finding all substrings
	FindSubstrings(input, length_input, palindromes, copyiesOccured);

	// printing palindromes
	cout << "Palindromes :\n";
	for (int i = 0; i < copyiesOccured; i++) 
	{
		/*loop to check for unique palindrome :
			logic -> if there is the same word in tha palindromes, the current one is skipped	
				*/
		for (int k = i + 1; k < copyiesOccured; k++) 
		{
			if (StrCompare(palindromes[i], palindromes[k]) == 0) 
			{
				counter++;
			}
		}		

		/**/
		if (counter == 0) 
		{
			cout << "palindromes[" << i << "]=";
			for (int j = 0; palindromes[i][j] != '\0'; j++) 
			{
				cout << palindromes[i][j];
			}
			cout << '\n';
		}

		/*nullifying the counter for next i iteration*/
		counter = 0;
	}


	return 0;
}