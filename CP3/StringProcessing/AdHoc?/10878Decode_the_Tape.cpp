#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
    string line, message = "", stop = "___________";
    getline(cin, line);
    getline(cin, line);
    while(line != stop) {
        int ascii = 0;
        for(int i = 0; i < 3; i++) {
            if(line[9 - i] == 'o') 
                ascii |= (1 << i);
        }
        for(int i = 3; i <= 6; i++) {
            if(line[8 - i] == 'o')
                ascii |= (1 << i);
        }
      
        message += char(ascii);
        getline(cin, line);
    }
    cout << message;
    return 0;
}