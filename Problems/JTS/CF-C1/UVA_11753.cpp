#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int seq[maxn], n, k, t;
map<pair<int, int> , int> dp[maxn];

int solve(int a, int b, int ret) {   
   if(ret > k) return 1000000;
   if(a >= b) return 0;
   pair <int, int> p = make_pair(b, ret);
   if(dp[a].find(p) != dp[a].end()) return dp[a][p];
   int ans = 0;
   if(seq[a] == seq[b]) ans = solve(a+1, b-1, ret);
   else ans = 1 + min(solve(a+1, b, ret + 1), solve(a, b-1, ret + 1));
   return dp[a][p] = ans;
}

int main() {
    scanf("%d", &t);
    for(int curr = 1; curr <= t; curr++) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
            dp[i].clear();
        }

        int ans = solve(0, n-1, 0);
        printf("Case %d: ", curr);
        if(ans == 0) printf("Too easy");
        else if(ans > k) printf("Too difficult");
        else printf("%d", ans);
        printf("\n");
    }
}