#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn], b[maxn], pref[maxn], n;
ll dp[maxn];

int query(int i, int j) {
    if(j < 0) return 0;
    int ans = pref[j];
    if(i > 0) ans -= pref[i-1];
    return ans;
}

ll solve(ll i) {
    if(i < 0) return 0LL;
    ll * p = &dp[i];
    if(*p != -1) return *p;
    ll left =  a[i] - b[i], dest = query(left, a[i]-1LL);
    return *p = dest + solve(i - dest - 1);
}

int main() {
    memset(pref, 0, sizeof(pref));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    int maxA = 0;
    for(int i = 0; i < n; i++) {
        int at, bt;
        scanf("%d%d", &at, &bt);
        a[i] = at;
        b[i] = bt;
        pref[at]++;
        maxA = max(at, maxA);
    }
    for(int i = 0; i <= maxA; i++)    
        if(i > 0) pref[i] += pref[i-1];
    for(int i = n-1; i >= 0; i--)
        if(dp[i] == -1) solve(i);
    
    ll ans = n;
    for(int i = 0; i < n; i++) {
        ans = min(n - i - 1 + dp[i], ans);
    }
    cout << ans << endl;
}