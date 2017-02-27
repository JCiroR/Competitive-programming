#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <sstream>

using namespace std;

string encodeIt(string);

int main(void) {
    string word;
    string code;
    
    cout << setw(13) << "NAME" << setw(21 + 12) << "SOUNDEX CODE" << endl;
    while(cin >> word) {
        code = encodeIt(word);
        cout << setw(9 + word.size()) << word << setw(34 + code.size() - 9 - word.size()) << code << endl;
    }
    cout << setw(32) << "END OF OUTPUT" << endl;
    return 0;
}

string encodeIt(string word) {
    map<char, int> codeGuide;
    codeGuide['A'] = -1;
    codeGuide['E'] = -1;
    codeGuide['I'] = -1;
    codeGuide['O'] = -1;
    codeGuide['U'] = -1;
    codeGuide['Y'] = -1;
    codeGuide['W'] = -1;
    codeGuide['H'] = -1;

    codeGuide['B'] = 1;
    codeGuide['P'] = 1;
    codeGuide['F'] = 1;
    codeGuide['V'] = 1;

    codeGuide['C'] = 2;
    codeGuide['S'] = 2;
    codeGuide['K'] = 2;
    codeGuide['G'] = 2;
    codeGuide['J'] = 2;
    codeGuide['Q'] = 2;
    codeGuide['X'] = 2;
    codeGuide['Z'] = 2;

    codeGuide['D'] = 3;
    codeGuide['T'] = 3;
    codeGuide['L'] = 4;
    codeGuide['M'] = 5;
    codeGuide['N'] = 5;
    codeGuide['R'] = 6;

    int lastCharCode = codeGuide[word[0]];
    string code = "";
    code += word[0];
    
    for(int i = 1; i < word.size(); i++) {
        if(code.size() > 3 ) break;
        if(codeGuide[word[i]] != lastCharCode && codeGuide[word[i]] != -1){
            ostringstream converter;
            converter << codeGuide[word[i]];
            code += converter.str();
        }
        lastCharCode = codeGuide[word[i]];
    }
    
    while(code.size() < 4) 
        code += "0";
    return code;
}