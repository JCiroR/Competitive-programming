#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[61][61];
string s;

long long solve(int a, int b) {
    if(a > b) return 1;
    ll * p = &dp[a][b];
    if(*p != -1) return *p;
    ll ans = 0;
    ans += solve(a+1, b) + solve(a, b-1) - solve(a+1, b-1);
    if(s[a] == s[b]) ans += solve(a+1, b-1);

    return *p = ans;
}

int main() {
    int t; cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        cout << solve(0, s.size()-1) - 1 << endl;
    }
}