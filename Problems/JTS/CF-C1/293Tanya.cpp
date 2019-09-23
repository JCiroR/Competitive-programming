#include <string>
#include <cstring>
#include <iostream>
#include <cctype>

using namespace std;

int times[256];

int main() {
    memset(times, 0, sizeof(times));
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < t.size(); i++) times[t[i]]++;
    int y = 0, w = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(times[c] > 0) {
            times[c]--;
            y++;
            s[i] = '*';
        }
    }
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '*') continue;
        if(islower(c) && times[toupper(c)] > 0) {
            times[toupper(c)]--;
            w++;
        } else if(isupper(c) && times[tolower(c)] > 0) {
            times[tolower(c)]--;
            w++;
        }
    }
    cout << y << " " << w << endl;
}