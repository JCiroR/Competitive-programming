#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[110][5];
int act[110], n;

ll solve(int index, int bef) {
    if(index == n) return 0;
    if(dp[index][bef] != -1) return dp[index][bef];
    ll ans = 200, pos = act[index];
    if((pos == 1 || pos == 3 ) && bef != 1) 
        ans = solve(index + 1, 1);
    if((pos == 2 || pos == 3) && bef != 2)
        ans = min(ans, solve(index + 1, 2));
    ans = min(ans, 1LL + solve(index + 1, 0));
    return dp[index][bef] = ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> act[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
}