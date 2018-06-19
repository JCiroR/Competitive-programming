#include <bits/stdc++.h>
using namespace std;

string s;
int n, p;

bool end() { return p >= n;}

bool slump() {
    if(end() || (s[p++] != 'D' && s[p-1] != 'E') || end()) return false;
    if(s[p++] != 'F' || end()) return false;
    while(s[p] == 'F') {
        p++;
        if(end()) return false;
    }
    char fol = s[p++];
    if(fol == 'G') return true;
    else {
        p--;
        return slump();
    }
}

bool slimp() {
    if(end() || s[p++] != 'A' || end()) return false;
    char fol = s[p++];
    if(fol == 'H') return true;
    else if(fol == 'B') return slimp() && !end() && s[p++] == 'C';
    else {
        p--;
        return slump() && !end() && s[p++] == 'C';
    }
}

bool slurpy() {
    return slimp() && slump() && end();
}

int main() {
    int t; scanf("%d", &t);
    printf("SLURPYS OUTPUT\n");
    while(t--) {
        cin >> s;
        n = s.size(), p = 0;
        if(slurpy()) printf("YES\n");
        else printf("NO\n");
    }
    printf("END OF OUTPUT\n");
}