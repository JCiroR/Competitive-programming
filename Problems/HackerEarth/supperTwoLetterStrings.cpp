#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 * 2, mod = 1e9 + 7;
int dp[N][11], n, p, t;

int solve(int length, int prev) {
    if(length == 1) return 1;
    int &m = dp[length][prev];
    if(m != -1) return m;

    int ans = solve(length - 1, 0) % mod;
    if(prev  + 1 < p) ans += solve(length - 1, prev + 1) % mod;
    ans %= mod;
    
    return m = ans;
}


int main() {
    cin >> t;
    while(t--) {
        cin >> n >> p;
        memset(dp, -1, sizeof(dp));
        cout << solve(n, 0) << endl;
    }
}