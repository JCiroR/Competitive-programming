#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, K = 101, mod = 1e9 + 7;
ll dp[N][K];

int main() {
    for(int k = 0; k < K; k++) dp[0][k] = 1;
    for(int k = 0; k < K; k++)
        for(int i = 1; i < N; i++) 
            for(int j = 1; j <= min(k, i); j++) {
                dp[i][k] += dp[i - j][k];
                dp[i][k] %= mod;
            }
    int t; scanf("%d", &t);
    while(t--) {
        int x, k;
        scanf("%d %d", &x, &k);
        printf("%lld\n", dp[x][k]);
    }
}