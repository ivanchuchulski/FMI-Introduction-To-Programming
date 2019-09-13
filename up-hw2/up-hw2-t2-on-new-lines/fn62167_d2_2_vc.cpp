/* 
	I don't exactly remember the problem, but i think it required
	each word of a fixed length inputted sentence to be printed on a new line
	and the output should not contain any punctuation signs.
	The frame around the words was required too and shown in a given
	example in the homework.
*/

/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 2
* @compiler VC
*
*/


#include <iostream>
#include <iomanip>
#include <functional>

using std::cout;
using std::cin;
using std::setw;

size_t StrLen(const char* src)
{
	if (src == nullptr)
		return 0;

	const char* reader = src;

	while (*reader != '\0')
		reader++;

	return reader - src;
}

bool IsPunctuationlSign(char symbol)
{
	const char PUNCTUATION_SIGNS[] = ".,!?\"\'";

	for (int i = 0; i < StrLen(PUNCTUATION_SIGNS); i++)
	{
		if (symbol == PUNCTUATION_SIGNS[i])
		{
			return true;
		}
	}

	return false;
}

bool IsWhitespace(char symbol)
{
	const char WHITESPACES[] = "\n\t ";

	for (int i = 0; i < StrLen(WHITESPACES); i++)
	{
		if (symbol == WHITESPACES[i])
		{
			return true;
		}
	}

	return false;
}

void SqueezeConsecutiveSymbols(char* sentence, int& len, std::function<bool(char)> IsSignToSqueeze)
{
	for (int i = 0; i < len; i++)
	{
		if (IsSignToSqueeze(sentence[i]))
		{
			int nextNonPunctSignIndex = i + 1;

			// advancing forward to the first sign
			while (IsSignToSqueeze(sentence[nextNonPunctSignIndex]) && nextNonPunctSignIndex < len)
				nextNonPunctSignIndex++;

			int positionShiftsToTheLeft = nextNonPunctSignIndex - i - 1;

			// shifting the elements
			for (int j = nextNonPunctSignIndex; j < len; j++)
				sentence[j - positionShiftsToTheLeft] = sentence[j];

			// nullifying the moved part
			for (int k = len - positionShiftsToTheLeft; k < len; k++)
				sentence[k] = '$';
			
			len -= positionShiftsToTheLeft;
		}
	}
}

void RemoveInitialOccurenceOfSymbol(char* sentence, int& len, std::function<bool(char)> IsSignToRemove)
{
	if (IsSignToRemove(sentence[0]))
	{
		for (int i = 1; i < len; i++)
			sentence[i - 1] = sentence[i];
	}

	len -= 1;
}

void RemoveSigns(char* sentence, int& len, std::function<bool(char)> IsSignToRemove)
{
	for (int i = 0; i < len; i++)
	{
		if (IsSignToRemove(sentence[i]))
		{
			for (int j = i + 1; j < len; j++)
			{
				sentence[j - 1] = sentence[j];
			}

			len -= 1;
			sentence[len] = '\0';
		}
	}
}

void PutWordsOnNewLines(char* input, const int len) 
{
	for (int i = 0; i < len; i++) 
	{
		if (input[i] == ' ' || input[i] == '\t') 
		{
			input[i] = '\n';
		}
	}
}

int LongestWordLength(char* input, const int len) 
{
	int currentLen = 0;
	int longestLen = 0;

	for (int i = 0; i < len; i++) 
	{
		if (input[i] != '\n') 
		{
			currentLen++;

			if (currentLen >= longestLen) 
			{
				longestLen = currentLen;
			}
		}
		else 
		{ 
			currentLen = 0;
		}
	}

	return longestLen;
}


void DrawHorizontalFrame(int longestWordLen) 
{
	for (int i = 0; i < longestWordLen + 2; i++) 
	{
		cout << '-';
	}

	cout << '\n';
}

//frameMiddle
void DrawFrame(char* sentence, const int len)
{
	int maxWordLen = LongestWordLength(sentence, len);

	// upper part of frame
	DrawHorizontalFrame(maxWordLen);

	// middle part of frame
	int counter = -1;
	cout << '|';
	for (int i = 0; i < len; i++) 
	{
		if (sentence[i] != '\n') 
		{
			cout << sentence[i];
			counter++;
		}
		else 
		{
			cout << setw(maxWordLen - counter) << '|';
			cout << sentence[i];						 // printing the new line
			cout << '|';								//printing the beginning of the frame
			counter = -1;
		}
	}
	//last line
	cout << setw(maxWordLen - counter) << '|';

	// lower part of frame
	cout << '\n';
	DrawHorizontalFrame(maxWordLen);
}

int main() 
{
	const size_t MAX_SENTENCE_SIZE = 101;

	int sentenceLen = 0;
	char sentence[MAX_SENTENCE_SIZE];

	int formattedSentenceLen = 0;
	char formattedSentence[MAX_SENTENCE_SIZE];

	std::memset(sentence, 0, MAX_SENTENCE_SIZE);
	std::memset(formattedSentence, 0, MAX_SENTENCE_SIZE);

	cout << "Enter a sentence : ";
	cin.getline(sentence, MAX_SENTENCE_SIZE);

	sentenceLen = StrLen(sentence);

	SqueezeConsecutiveSymbols(sentence, sentenceLen, IsWhitespace);
	SqueezeConsecutiveSymbols(sentence, sentenceLen, IsPunctuationlSign);

	RemoveSigns(sentence, sentenceLen, IsPunctuationlSign);

	PutWordsOnNewLines(sentence, sentenceLen);

	DrawFrame(sentence, sentenceLen);

	return 0;
}