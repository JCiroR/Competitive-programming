#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, chars = "abcdefghijklmnopqrstuv";

char getC(int i) {
    for(int j = 0; j < chars.size(); j = ((j+1)%chars.size())) {
        if(chars[j] != s1[i] && chars[j] != s2[i]) return chars[j];
    }
}

int main() {
    int n, t;
    cin >> n >> t >> s1 >> s2;
    int d = 0;
    s3 = s1;
    for(int i = 0; i < n; i++) {
        s3[i] = s1[i];
        if(s1[i] != s2[i]) {
            d++;
            s3[i] = getC(i);
        }
    }
    if(d <= t) {
        int left = t - d;
        for(int i = 0; i < n && left > 0; i++) {
            if(s1[i] == s2[i]) {
                s3[i] = getC(i);
                left--;
            }
        }
        cout << s3 << endl;
    } else if(d > 2 * t) cout << -1 << endl;
    else {
        for(int i = 0, j = d - t; i < n && j > 0; i++) {
            if(s3[i] != s1[i] && s3[i] != s2[i]) {
                s3[i] = s1[i];
                j--;
            }
        }
        for(int i = 0, j = d - t; i < n && j > 0; i++) {
            if(s3[i] != s1[i] && s3[i] != s2[i]) {
                s3[i] = s2[i];
                j--;
            }
        }
        cout << s3 << endl;
    }
}