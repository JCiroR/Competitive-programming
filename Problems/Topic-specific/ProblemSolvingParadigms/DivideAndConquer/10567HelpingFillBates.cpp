#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

const int MAXN = 52;
vector<int> byState[MAXN];

int getIndex(char s) {
    if(isupper(s)) return s - 'A';
    else return 26 + s - 'a';
}

int main(void) {
    fill(byState, byState + MAXN - 1, vector<int>());
    string s, query; int q;
    cin >> s >> q;
    for(int i = 0; i < s.size(); i++) {
        byState[getIndex(s[i])].push_back(i);
    }
    while(q--) {
        cin >> query;
        int first, last, leftMostIndex = -1;
        bool answered = false;
        for(int i = 0; i < query.size(); i++) {
            vector<int> currv = byState[getIndex(query[i])];
            vector<int>::iterator a = upper_bound(currv.begin(), currv.end(), leftMostIndex);
            if(a == currv.end()) {
                cout << "Not matched\n"; 
                answered = true;
                break;
            } else {
                if(i == 0) first = *a;
                leftMostIndex = *a;
                last = *a;
            } 
        }
        if(!answered) printf("Matched %i %i\n",first, last);
    }
    return 0;
}