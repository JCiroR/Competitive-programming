#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5, M = 200, mod = 1e9 + 7;
int dp[N + 10][M][2];
int a[M], b[M], Q, n;

int solve(int ind, int diff, bool A) {
    if(ind == n)
     if(diff <= Q) return 1;
     else return 0;

    int &p = dp[diff][ind][A];
    if(p != -1) return p;

    int ans = 0;
    if(!A) diff *= -1;

    int thisDiff = diff + a[ind];
    ans += solve(ind + 1, abs(thisDiff), thisDiff >= 0);
    ans %= mod;

    thisDiff = diff - b[ind];
    ans += solve(ind + 1, abs(thisDiff), thisDiff >= 0);
    ans %= mod;

    thisDiff = diff + a[ind] - b[ind];
    ans += solve(ind + 1, abs(thisDiff), thisDiff >= 0);
    ans %= mod;

    thisDiff = diff;
    ans += solve(ind + 1, abs(thisDiff), thisDiff >= 0);
    ans %= mod;

    return p = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    scanf("%d", &Q);
    solve(0, 0, true);
    printf("%d\n", dp[0][0][true]);
}