#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
    string currLine;
    bool closed = true;
    char quotes = '\"';

     while(getline(cin,currLine)) {
         int pos;
        while(currLine.find(quotes) != string::npos) {
            pos = currLine.find(quotes);
            if(closed) {
                currLine[pos] = '`';
                currLine.insert(pos + 1,"`");
                closed = false;
            } else {
                currLine[pos] = '\'';
                currLine.insert(pos + 1,"'");
                closed = true;
            }
        }
        cout << currLine << endl;
    }
        
    return 0;
}