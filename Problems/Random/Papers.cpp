#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
point rec1[5], rec2[5];

int main() {
    string s;
    while(true){
    for(int i = 0; i < 4; i++) {
        if(cin >> s) {
            int nothing = 1;
        } else goto END;
        string num = "";
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == 0)   num += '1';
            else if(s[j] != '.') num += s[j];
        }
        cin >> s;
        string num2 = "";
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == 0)   num2 += '1';
            if(s[j] != '.') num2 += s[j];
        }
        // cout << stoll(num) << endl;
        rec1[i] = point(stoll(num), stoll(num2));
    }
        for(int i = 0; i < 4; i++) {
        cin >> s;
        string num = "";
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == 0)   num += '1';
            else if(s[j] != '.') num += s[j];
        }
        cin >> s;
        string num2 = "";
        for(int j = 0; j < s.size(); j++) {
            if(j == 0 && s[j] == 0)   num2 += '1';
            if(s[j] != '.') num2 += s[j];
        }
        rec2[i] = point(stoll(num), stoll(num2));
    }

    ll p1xl = 0, p1yl = 0;
    for(int i = 0; i < 4; i++) {
        p1xl += rec1[i].first;
        p1yl += rec1[i].second;
    }
    ll p2xl = 0, p2yl = 0;
    for(int i = 0; i < 4; i++) {
        p2xl += rec2[i].first;
        p2yl += rec2[i].second;
    }
    if(p2xl == p1xl && p2yl == p1yl) {
        p2xl = 0;
        p2yl = 0;
    }
    double p1x = p1xl, p1y = p1yl, p2x = p2xl, p2y = p2yl;
    printf("YES %.5lf %.5lf %.5lf %.5lf\n", p1x/4e5, p1y/4e5, p2x/4e5, p2y/4e5);
}
END:
return 0;
}