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
using namespace std;

//30 words with max length 20
const char WORD_DATABASE[][21] = {
	"student" ,"refrigerator", "fmi", "university", "bulgaria", 
	"guitar", "cooper", "distance", "butter", "expect", 
	"unite", "branch", "educated", "truck", "open",
	"range", "modern", "history", "attack",	"smoke",
	"decision", "drag", "carbon", "squeeze", "wing"
	"shop", "visitor", "seed", "dynamic", "counterdemontrators", "freedom"

};

enum difficultyLevel {
	impossible = 1,
	hard = 3,
	medium = 5,
	easy = 7,
};

//selecting word from database
/*selectWord(guessWord, WORD_DATABASE[indexRand]); in main
void selectWord( char *input, const char *global) {
	int counter = 0;
	for (int i = 0; global[i] != '\0'; i++) {
		input[i] = global[i];
		counter++;
	}
	//endign the array
	input[counter] = '\0';
}*/

//inputControl
int safetyInputInteger(int lowerBound, int upperBound) {
	int numberInput;

	do {
		cout << "Select level of difficulty [1-4] : ";
		cin >> numberInput;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while ((numberInput < lowerBound || numberInput > upperBound));

	return numberInput;
}

//converting upper to lower function
char toLower(char letter) {
	if (letter >= 'A' && letter <= 'Z') {
		return letter + ('a' - 'A');
	}
	return letter;
}

//copying function
char *strCopy(char *dest, const char *source) {
	do {
		*dest++ = *source;
	} while (*source++ != '\0');
	return dest;
}

//comparing function
int strCompare(char *a, char *b) {
	unsigned char a1;
	unsigned char b1;
	int difference;
	do {
		a1 = (unsigned char)*a++;
		b1 = (unsigned char)*b++;
		difference = a1 - b1;
	} while ((difference == 0) && (a1 != '\0'));

	return difference;
}

//filling with '_'
void fillUnderscore(char *outWord) {
	char firstLetter = outWord[0];
	char lastLetter;
	for (int i = 1; outWord[i] != '\0'; i++) {
		lastLetter = outWord[i];
	}
	//filling with '_'
	for (int j = 0; outWord[j] != '\0'; j++) {
		if (outWord[j] == firstLetter || outWord[j] == lastLetter)
			//do nothing
			;
		else {
			outWord[j] = '_';
		}
	}
}

//update
void update(char letter, char *outWord, int pos) {
	//updating
	for (int j = 0; outWord[j] != '\0'; j++) {
		if (j == pos) {
			outWord[j] = letter;
			break;
		}
	}
}

//check if input is in the word
bool guessSearch(char userInput, char *guessWord, char *outWord) {
	int counter = 0;
	for (int i = 1; guessWord[i] != '\0'; i++) {
		if (userInput == guessWord[i]) {
			update(userInput, outWord, i);
			counter++;
		}
	}
	//if counter is > 0, a letter was guessed right
	if (counter == 0)
		return false;
	else
		return true;
}

int main() {
	srand(time(NULL));
	int indexRand = rand() % 31;	//getting random number from [0,30]

	char guessWord[21];
	char outWord[21];	//word to be displayed
	char userInput;
	int difficulty;
	int attemptsLeft;

	//selecting word from database
	strCopy(guessWord, WORD_DATABASE[indexRand]);

	//4 levels of difficulty


	//safe inputControl
	difficulty = safetyInputInteger(1, 4);

	//unsafe
	//cout << "Select level of difficulty [1-4] : ";
	//cin >> difficulty;

	//determine attempts
	switch (difficulty)
	{
		case 1:
			attemptsLeft = easy;
			break;
		case 2:
			attemptsLeft = medium;
			break;
		case 3:
			attemptsLeft = hard;
			break;
		case 4:
			attemptsLeft = impossible;
			break;
	default:
		attemptsLeft = easy;
		break;
	}

	//copying the random word and filling with _
	strCopy(outWord, guessWord);
	fillUnderscore(outWord);

	//gameOn
	while (attemptsLeft > 0) {

		cout << "Word : " << outWord << ";\t" << "Attempts : " << attemptsLeft << '\n';
		cout << "Enter a letter : ";
		cin >> userInput;

		//handling upperCase
		userInput = toLower(userInput);

		//see if the letter was in the word
		bool found = guessSearch(userInput, guessWord, outWord);

		if (found == false) {
			//letter is not in the word
			cout << "Error\n";
			attemptsLeft = attemptsLeft - 1;
		}
		else {
			//check if you guessed all the letters
			if (strCompare(guessWord, outWord) == 0) {
				cout << "Success, the word is : \"" << outWord << "\"";
				break;
			}
		}
	}
	
	if (attemptsLeft == 0) {
		//gameOver
		cout << "Sorry, you lose\n";
//		system("pause");
		return 0;
	}

	cout << '\n';
//	system("pause");
	return 0;
}