#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const int maxl = 1010;
ll dp[maxl][maxl], cuts[51];
int l, n;

ll solve(int a, int b, int i) {
    ll * p = &dp[a][b];
    if(*p != -1) return *p;

    ll cost = 1000*100;
    bool valid = false;
    for(int i2 = i; i2 < n; i2++) {
        if(cuts[i2] == a) continue;
        if(cuts[i2] >= b) break;
        valid = true;
        ll curr = solve(a, cuts[i2], i) + solve(cuts[i2], b, i2);
        cost = min(cost, curr);
    }
    if(valid) cost += b - a;
    else cost = 0;

    return *p = cost;
}

int main() {
    while(scanf("%d", &l) == 1 && l) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &cuts[i]);
        printf("The minimum cutting is %d.\n", solve(0, l, 0));
    }
}