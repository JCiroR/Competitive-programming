#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <sstream>

using namespace std;

string removeBlanks(string u) {
    int left = 0, right = 0;
    for(int i = 0; i < u.size(); i++) {
        if(u[i] != ' ') {
            left = i;
            break;
        }
    }
    for(int i = u.size()-1; i >= 0; i--) {
        if(u[i] != ' ') {
            right = i;
            break;
        }
    }
    return u.substr(left, (right - left + 1));
}

int main(void) {
    regex e("[+-]?\\d+(\\.\\d+([eE][+-]?\\d+)?|[eE][+-]?\\d+)");
    string subject;
    while(getline(cin, subject) && subject != "*") {
        subject = removeBlanks(subject);
        if(regex_match(subject, e)) cout << subject << " is legal.\n";
        else cout << subject << " is illegal.\n";
    }
}