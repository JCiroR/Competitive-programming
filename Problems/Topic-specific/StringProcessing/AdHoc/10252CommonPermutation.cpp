#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int charsA[27], charsB[27];

int main(void) {
    string a, b;
    while(getline(cin, a) && getline(cin, b)) {
        memset(charsA, 0, sizeof(charsA));
        memset(charsB, 0, sizeof(charsB));
        for(int i = 0; i < a.size(); i++) charsA[a[i] - 'a']++;
        for(int i = 0; i < b.size(); i++) charsB[b[i] - 'a']++;
        string answ = "";
        answ.reserve(min(a.size(), b.size()));
        for(int i = 0; i < 27; i++) {
            int times = min(charsA[i], charsB[i]);
            answ.append(times, char(i + 'a'));
        }
        cout << answ << endl;
    }
    return 0;
}

