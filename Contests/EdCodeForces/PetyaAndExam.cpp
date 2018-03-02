#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool match(string word, string pattern, string goodLetters) {
    for(int i = 0; i < word.size(); i++) {
        if(word[i] != pattern[i]) {
            if(word[i])
        }
    }
}

int main(void) {
    char curr;
    string goodLetters = "";
    string badLetters = "";
    string letters = "abcdefghijklmnopqrstuvwxyz";

    while((curr = getchar()) != '\n') {
        letters[curr - 97] = '-';
        goodLetters += curr;
    }
    for(int i = 0; i < 26; i++)
        if(letters[i] != '-') badLetters += letters[i];
    string pattern;
    cin >> pattern;

    vector<int> questionIndices;
    int starIndex = -1;
   
    for(int i = 0; i < pattern.size(); i++) {
        if(pattern[i] == '?') questionIndices.push_back(i);
        if(pattern[i] == '*') starIndex = i;
    }
    int n;
    cin >> n;
    string query;
    
    while(n--) {
        cin >> query;
      
    }
    

    return 0;
}