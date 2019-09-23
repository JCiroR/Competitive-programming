#include <string>
#include <iostream>

using namespace std;

int main(void) {
    int n; string s;
    cin >> n;
    cin >> s;
    string answ;
    for(int i = n-1; i >= 0; i--)
        answ = answ.substr(0, answ.size()/2) + s[i] + answ.substr(answ.size()/2);
    cout << answ << endl;
}