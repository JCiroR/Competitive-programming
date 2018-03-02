/*
    WA, I don't know why
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 110;

int LCS[MAXN][MAXN], aS, bS;
string a[MAXN], b[MAXN];

int main(void) { 
    while(true) {
        bool something = false;
        string temp;
        aS = bS = 0;
        while(cin >> temp) {
            if(temp == "#") break;
            a[aS++] = temp;
        }
        while(cin >> temp) {
            something = true;
            if(temp == "#") break;
            b[bS++] = temp;
        }
        if(!something) break;
        for(int i = 0; i <= aS; i++) for(int j = 0; j <= bS; j++) {
            if(i == 0 || j == 0) LCS[i][j] = 0;
            else if(a[i-1] == b[j-1]) LCS[i][j] = a[i-1].size() + LCS[i-1][j-1];
            else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
        vector<string> answ;
        answ.reserve(100);
        int i = aS, j = bS;
        while(i && j) {
            if(a[i-1] == b[j-1]) {
                answ.push_back(a[i-1]);
                i--; j--;
            } 
            else if(LCS[i][j-1] > LCS[i-1][j]) j--;
            else i--;
        } 
        cout << answ[answ.size()-1];
        for(int i = answ.size()-2; i >= 0; i--) cout << " " << answ[i];
        cout << endl;
    }
}