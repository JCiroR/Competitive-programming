#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int dp[MAXN][MAXN];
string s;

int func(int a, int b) {
    if(b - a < 1) return 0;
    int * p = &dp[a][b];
    if(*p != -1) return *p;
    int ans;
    if(s[a] == s[b]) ans = func(a+1, b-1);
    else {
        ans = func(a+1, b);
        ans = min(ans, func(a, b-1));
        ans = min(ans, func(a+1, b-1));
        ans += 1;
    }
    return (*p = ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        cout << "Case " << i << ": " << func(0, s.size() - 1) << endl;
    }
}