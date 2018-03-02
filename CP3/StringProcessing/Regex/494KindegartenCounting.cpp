#include <regex>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main(void) {
    string subject;
    regex e("[a-zA-Z]+");
    while(getline(cin, subject)) {
        regex_iterator<string::iterator> rit(subject.begin(), subject.end(), e), rend;
        cout << distance(rit, rend) << endl;
    }
}