#include <bits/stdc++.h>
using namespace std;

string s1 = "aeiou";
string s2 = "bcdfghjklmnpqrstvwxyz";
int times[300];

bool isVow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int t; 
    string s, ans;
    cin >> t;
    while(t--) {
        memset(times, 0, sizeof(times));
        cin >> s;
        ans.clear();
        for(int i = 0; i < s.size(); i++) {
            char c = s[i]; 
            int idx;
            if(isVow(c)) {
                idx = lower_bound(s1.begin(), s1.end(), c) - s1.begin();
                idx += times[c] * s1.size();
                idx %= s2.size();
                ans.push_back(s2[idx]);
            } else {
                idx = lower_bound(s2.begin(), s2.end(), c) - s2.begin();
                idx += times[c] * s2.size();
                idx %= s1.size();
                ans.push_back(s1[idx]);
            }
            times[c]++;
        }
        cout << ans << endl;   
    }
}