#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p, q;
const ll nel = -11000;
ll dp[110][110][2], help[110][110];

ll rew(int i, int k, int j, int l) {
    ll subRect = help[k][l];
    if(i > 0) subRect -= help[i - 1][l];
    if(j > 0) subRect -= help[k][j - 1];
    if(i > 0 && j > 0) subRect += help[i-1][j-1];
    return subRect;
}

ll solve(int izq, int inf, int pl) {
    // printf("%d %d %d\n", izq, inf, pl);
    if(izq >= q || inf < 0 || inf >= p) return 0;
    ll &a = dp[izq][inf][pl];
    if(a != nel) return a;
    ll ans = nel, curr;
    if(pl == 0) {
        for(int i = izq; i < q; i++) {
            curr = rew(izq, i, 0, inf) + solve(i+1, inf, 1);
            ans = max(ans, curr);
        }
    } else {
        ans *= -1;
        for(int i = inf; i >= 0; i--) {
            curr = solve(izq, i + 1, 0);
            ans = min(ans, curr);
        }
    }
    return a = ans;
}

int main() {
    int st = 1;
    for(int i = 0; i < 101; i++) {
        int st2 = st;
        for(int j = 0; j < 101; j++) {
            help[i][j] = st2;
            st2 *= -1;
            if(i > 0) help[i][j] += help[i-1][j];
            if(j > 0) help[i][j] += help[i][j-1];
            if(i > 0 && j > 0) help[i][j] -= help[i-1][j-1];
        }
        st *= -1;
    }
    scanf("%d%d", &p, &q);
    fill_n(&dp[0][0][0], 110*110*2, nel);
    ll thot = rew (0, p - 1, 0, q -1);
    // cout << thot << endl;
    ll p1 = solve(0, p-1, 0);
    ll p2 = thot - p1;
    printf("%lld\n", p1 - p2);
}
