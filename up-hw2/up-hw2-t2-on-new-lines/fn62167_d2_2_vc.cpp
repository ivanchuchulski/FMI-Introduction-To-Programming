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

using namespace std;

//array of signs, that need to be removed
const char SPECIAL_SIGNS[] = { '.', '!', '?', ',', '\"', '\0'};

//removing signs
void RemoveSigns(const char* input, char* destination) 
{
	int k = 0;
	int counter = 0;
	//scaning the sentence for special signs
	for (int i = 0; input[i] != '\0'; i++) 
	{
		for (int j = 0; SPECIAL_SIGNS[j] != '\0'; j++) 
		{
			if (input[i] == SPECIAL_SIGNS[j]) 
			{
				counter++;
			}
		}
		//check if there wasn't a special sign, write in destination arr
		if (counter == 0) 
		{
			destination[k] = input[i];
			k++;
		}
		counter = 0;	//for next iteration

	}
	//add the terminating zero at the end
	destination[k] = '\0';
}

//putting words on new lines
void onNewLines(char *input) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ' || input[i] == '\t') {
			input[i] = '\n';
		}
	}
}

//getting the longest word in the sentence
int longestWord(char *input) {
	int tCounter = 0;
	int longest = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] != '\n') {
			tCounter++;
			//cout << "br : " << tCounter;
			if (tCounter >= longest) {
				longest = tCounter;
			}
		}
		else { 
			tCounter = 0;
		}
	}
	return longest;
}

//frameUp && frameDown 
void frameUpAndDown(int maxWord) {
	for (int i = 0; i < maxWord + 2; i++) {
		cout << '-';
	}
	cout << '\n';
}

//frameMiddle
void middleFrame(char *sentence, int maxWord) {
	//frameUp
	frameUpAndDown(maxWord);

	//middle frame
	int counter = -1;
	cout << '|';
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] != '\n') {
			cout << sentence[i];
			counter++;
		}
		else {
			cout << setw(maxWord - counter) << '|';
			cout << sentence[i] << '|';
			counter = -1;
		}
	}
	//last line
	cout << setw(maxWord - counter) << '|';

	//frameDown
	cout << '\n';
	frameUpAndDown(maxWord);
}

int main() {

	char sentence[101];
	char modSentence[101];	//modified sentence, without special signs

	cout << "Enter a sentence : ";
	cin.getline(sentence, 101);
	cout << '\n';

	//remove exclamation, question marks, commmas etc
	RemoveSigns(sentence, modSentence);

	//onNewLines
	onNewLines(modSentence);

	//longest word in the sentence
	int maxWord = longestWord(modSentence);

	//frame function
	middleFrame(modSentence, maxWord);

	//checks
	/*	cout << "rmve : \n" << modSentence << endl;
	cout << "onNewLins : \n" << modSentence << endl;
	cout << "max word : " << maxWord << '\n';*/
	cout << '\n';
//	system("pause");
	return 0;
}