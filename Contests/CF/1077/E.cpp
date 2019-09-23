#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 210;

ll memo[N][N][N];
ll a[N];
int n, k, x;

ll dp(int idx, int lapse, int rem) {
    if(idx >= n) return true;
    if(lapse < 0) return -1;


    ll & ans = memo[idx][lapse][rem];

    if(ans != -2) return ans;
    if(rem == 0 && idx + lapse <= n - 1) return ans = -1;
    else if(rem == 0) return ans = 0;
    
    ans = -1;
    ll val = dp(idx + 1, k - 1, rem - 1);
    if(lapse == 0 && val == -1) return ans = -1;
    if(val != -1) ans = a[idx] + val;

    if(lapse > 0) 
        ans = max(ans, dp(idx + 1, lapse - 1, rem));
    
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &k, &x);
    fill_n(&memo[0][0][0], N * N * N, -2);
    for(int i = 0; i < n; i++)
      cin >> a[i];
    cout << dp(0, k - 1, x) << endl;
}