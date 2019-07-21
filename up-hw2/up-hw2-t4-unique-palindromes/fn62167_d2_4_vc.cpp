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

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int max_len = 11;

int strCompare(const char* str1, const char* str2) {
	
	char c1, c2;
	int diff;

	do {
		c1 = *str1++;
		c2 = *str2++;

		diff = c1 - c2;

	} while ((diff == 0) && (c1 != '\0'));

	return diff;
}

/*	string length	*/
int strLength(char *input) {

	char *pLink = input;

	while (*pLink != '\0') {
		pLink++;
	}
	//returning the length
	return (pLink - input);

}

/*	copying function	*/
char *strCopy(char *dest, const char *source) {
	do {
		*dest++ = *source;
	} while (*source++ != '\0');
	return dest;
}

/*Palindrome check*/
bool isPali(char *input) {
	int length = strLength(input);

	for (int i = 0; i < (length / 2); i++) {
		if (input[i] != input[length - i - 1]) {
			//cout << input[i] << "!=" << input[length - i - 1] << endl;
			//some character is different
			return false;
		}
	}
	//the word is palindrome
	return true;
}

/*Find substrings*/
void findSubstr(char *input, char arr[][max_len], int& ref_copies) {

	int length = strLength(input);
	char* word = new char[length + 1];		//creating dynamic array for each substring
	int k = 0;
	int q = 0;

	/*searching the string; i is the pivot(starting point) */
	for (int i = 0; i < (length - 1); i++) {
		word[k] = input[i];
		k++;
		for (int j = (i + 1); j < length; j++) {
			word[k] = input[j];
			k++;
			word[k] = '\0';	//adding the terminating null

			/*palindrome check*/
			if (isPali(word) == true) {

				/*printing the pali*/
				/*for (int q = 0; word[q] != '\0'; q++) {
					cout << word[q];
				}
				cout << endl;*/

				/*copying to paliArr*/
				strCopy(arr[q], word);
				q++;
			}
		}
		/*set k to zero for next 'i' iteration*/
		k = 0;
	}

	//freeing up heap memory
	delete[] word;

	ref_copies = q;
	cout << "copies, all palindromes : " << q << endl;
}

int main() {

	char input[51];

	/*	getting user input	*/
	cout << "Input[max 50 symbols] : ";
	cin.getline(input, 51);

	
	int senLen = strLength(input);
	//max_len word, (max_len - 1) length of a word + 1 for '\0'	11, 10
	char paliArr[max_len][max_len];
	int copyiesOccured = 0;
	int counter = 0;

	/*		setting paliArr		*/
	//for (int i = 0; i < max_len; i++) {
	//	for (int j = 0; j < max_len; j++) {
	//		//ending with terminating zero
	//		//if (j == (max_len - 1)) {
	//		if (j == (senLen + 1)) {
	//			paliArr[i][j] = '\0';
	//			break;
	//		}
	//		//otherwise fill with
	//		paliArr[i][j] = '*';
	//	}
	//}

	for (int i = 0; i < ::max_len; ++i) {
		memset(paliArr[i], 0, max_len);
	}


	/*logic -> finding all substrings*/
	findSubstr(input, paliArr, copyiesOccured);

	/*printing palindroms*/
	cout << "Palindroms :\n";
	for (int i = 0; i < copyiesOccured; i++) {

		
		/*loop to check for unique palindrome :
			logic -> if there is the same word in tha paliArr, the current one is skipped	
				*/
		for (int k = i + 1; k < copyiesOccured; k++) {
			if (strCompare(paliArr[i], paliArr[k]) == 0) {
				counter++;
			}
		}		

		/**/
		if(counter == 0) {
			cout << "paliArr[" << i << "]=";
			for (int j = 0; paliArr[i][j] != '\0'; j++) {
				cout << paliArr[i][j];
			}
			cout << '\n';
		}

		/*nullifying the counter for next i iteration*/
		counter = 0;

	}



	std::cout << "\nPress ENTER to proceed : ";
	std::cin.get();
	return 0;
}