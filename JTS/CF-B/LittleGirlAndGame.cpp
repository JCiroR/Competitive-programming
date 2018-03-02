#include <string>
#include <cstring>
#include <iostream>
using namespace std;


int main() {
    string s;
    cin >> s;
    int count[50];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < s.size(); i++) count[s[i] - 'a']++;
    int notPair = 0;
    for(int i = 0; i < 40; i++) {
        if(count[i]&1) notPair++;
    }
    if(notPair&1 || notPair == 0) cout << "First\n";
    else cout << "Second\n";
}