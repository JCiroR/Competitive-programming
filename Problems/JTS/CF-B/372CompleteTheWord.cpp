#include <string>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int times[127], diff = 0, qMark = 0;
string s;

void fillall() {
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '?') s[i] = 'A';
}

void fix(int r) {
    if(diff == 26) return;
    int l = r - 25, next = 0;
    for(int i = l; i <= r; i++) {
        if(s[i] == '?') {
            for(int j = next; j <= 'Z' - 'A'; j++) {
                if(times[j] == 0) {
                    next = j;
                    break;
                }            
            }
            s[i] = char(next + 'A');
            next++;
        }
    }
}

int main() {
    cin >> s;
    memset(times, 0, sizeof(times));
    if(s.size() < 26) {
        cout << -1 << endl;
        return 0;
    } 
    for(int i = 0; i < 26; i++) {
        if(s[i] == '?') qMark++;
        else {
            if(times[s[i] - 'A'] == 0) diff++;
            times[s[i]-'A']++;
        }
    }
    if(diff == 26 || diff + qMark >= 26) {
        fix(25);
        fillall();
        cout << s << endl;
        return 0;
    }
    for(int i = 26; i < s.size(); i++) {
        char out = s[i-26], in = s[i];
        if(out == '?') qMark--;
        else {
            times[out - 'A']--;
            if(!times[out - 'A']) diff--;
        }
        if(in == '?') qMark++;
        else {
            if(times[s[i] - 'A'] == 0) diff++;
            times[s[i] - 'A']++;
        }
        if(diff >= 26 || qMark + diff >= 26) {
            fix(i);
            fillall();
            cout << s << endl;
            return 0;            
        }
    }
    cout << -1 << endl;
}