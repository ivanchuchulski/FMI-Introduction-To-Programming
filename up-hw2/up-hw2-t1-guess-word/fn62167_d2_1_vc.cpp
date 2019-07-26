/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;

//30 words with max length 20
const char WORD_DATABASE[30][21] = {
	"student" ,"refrigerator", "fmi", "university", "bulgaria",
	"guitar", "cooper", "distance", "butter", "expect",
	"unite", "branch", "educated", "truck", "open",
	"range", "modern", "history", "attack",	"smoke",
	"decision", "drag", "carbon", "squeeze", "wing"
	"shop", "visitor", "seed", "dynamic", "counterdemonstrators", "freedom"
};

enum DifficultyLevel
{
	impossible = 1,
	hard = 3,
	medium = 5,
	easy = 7,
};


int SafetyInputInteger(int lowerBound, int upperBound)
{
	int input;
	string difficulty_msg = "Select  difficulty [1-4], 1 : easy, 2 : medium, 3 : hard, 4 : impossible  -> ";

	do
	{
		cout << difficulty_msg;
		cin >> input;

		if (cin.fail())
		{
			cout << "Sorry, wrong input, try again!\n" << difficulty_msg;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

	} while ((input < lowerBound || input > upperBound));

	return input;
}

//converting upper to lower function
char ToLower(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
		return letter + ('a' - 'A');

	return letter;
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

//filling with '_'
void FillWithUnderscore(char* displayed_word, size_t len)
{
	char first_letter = displayed_word[0];
	char last_letter = displayed_word[len - 1];

	//filling with '_'
	for (size_t j = 1; j < len - 1; j++)
	{
		if (displayed_word[j] == first_letter || displayed_word[j] == last_letter)
			continue;
		else
			displayed_word[j] = '_';
	}
}

//check if input is in the word
bool UpdateDisplayedWord(char user_input, const char* word_to_guess, char* displayed_word, size_t len)
{
	int counter = 0;

	for (size_t i = 1; i < len - 1; i++)
	{
		if (user_input == word_to_guess[i])
		{
			displayed_word[i] = user_input;
			counter++;
		}
	}

	//if counter is > 0, a letter was guessed right
	return (counter > 0) ? true : false;
}

int main() {

	srand(time(NULL));
	int rand_indx = rand() % 31;	//getting random number from [0,30]

	char* word_to_guess = nullptr;
	char* displayed_word = nullptr;

	int difficulty;
	int attempts;

	//safe inputControl
	difficulty = SafetyInputInteger(1, 4);

	//determine attempts
	switch (difficulty)
	{
		case 1:
			attempts = DifficultyLevel::easy;
			break;
		case 2:
			attempts = DifficultyLevel::medium;
			break;
		case 3:
			attempts = DifficultyLevel::hard;
			break;
		case 4:
			attempts = DifficultyLevel::impossible;
			break;
		default:
			attempts = DifficultyLevel::easy;	// or set it to the hardest, idk
			break;
	}

	size_t word_len = StrLen(WORD_DATABASE[rand_indx]);
	word_to_guess = new char[word_len + 1];
	displayed_word = new char[word_len + 1];

	memset(word_to_guess, '\0', word_len + 1);
	memset(displayed_word, '\0', word_len + 1);

	StrCopy(displayed_word, WORD_DATABASE[rand_indx]);
	StrCopy(word_to_guess, displayed_word);
	FillWithUnderscore(displayed_word, word_len);

	//gameOn
	while (attempts > 0)
	{
		char user_input;

		cout << "Word to guess is : " << displayed_word << " \t " << "Attempts left : " << attempts << '\n';

		cout << "Enter a letter : ";
		cin >> user_input;

		user_input = ToLower(user_input);

		bool found = UpdateDisplayedWord(user_input, word_to_guess, displayed_word, word_len);

		if (!found)
		{
			cout << "Error, the letter is not in the word!\n";
			attempts -= 1;
		}
		else
		{
			// check if you guessed all the letters
			if (StrCompare(word_to_guess, displayed_word) == 0)
			{
				cout << "Success, the word is : " << displayed_word << '\n';
				break;
			}
		}
	}

	if (attempts == 0)
	{
		//gameOver
		cout << "Sorry, you lose, the word was : " << word_to_guess << '\n';
	}

	return 0;
}