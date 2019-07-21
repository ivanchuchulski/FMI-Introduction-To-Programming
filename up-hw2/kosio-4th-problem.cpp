#include <iostream>
#include <cstring>
#include <ctime>
 
using namespace std;
 
int ExtractSubstrings(char *string, char *substArr[])
{
    int len = strlen(string);
 
    int wordsToExtract = rand() % 3 + 2;
 
    int arrIdx = 0;
    while (wordsToExtract--)
    {
        int start = rand() % len;
        int wordLen = rand()%(len - start) + 1;
 
        substArr[arrIdx] = new char[wordLen + 1];
        memcpy(substArr[arrIdx], string + start, wordLen);
        substArr[arrIdx][wordLen] = 0;
 
        arrIdx++;
    }
 
    return arrIdx;
}
 
int main()
{
    srand(time(0));
 
    char word[50];
    memset(word, 0, 50);
 
    cin >> word;
 
    char *strings[20];
    int n = ExtractSubstrings(word, strings);
 
    for (int i = 0; i < n; i++)
    {
        cout << strings[i] << endl;
        delete strings[i];
    }
 
    system("pause");
}