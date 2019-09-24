#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int X = 701, N = 12, REM = 1 << 12;

ll memo[REM][X][N + 2];
int n, x, p[N + 2];
//Machetear parent
ll dp(int rem, int prevMax, int parent) {
    cout << bitset<12>(rem) << " ";
    printf("%d %d %d\n", prevMax, parent, x);

    if(rem == ( 1 << n) - 1) return 1;
    ll & ans = memo[rem][prevMax][parent];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i < n; i++) {
        if(parent == 12 && i == n-1) continue;
        if(!(rem & (1 << i))) {
            int newP = max(prevMax - p[parent], prevMax + 1 - p[i]);
            // cout << newP <<  " " << x << endl;
            if(newP <= x) {
                x-= newP;
                ans += dp((rem | (1 << i)), newP + p[i], i);
                x += newP;
            }
        }
    }
    return ans;
}

int main () {
    while(cin >> n >> x) {
        int greatest = -1;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            greatest = max(greatest, p[i]);
        }
        sort(p, p + n);
        memset(memo, -1, sizeof(memo));
        p[12] = greatest;
        cout << dp(0, greatest, 12) << endl;
    }
}