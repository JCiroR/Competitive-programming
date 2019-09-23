
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5, MOD = 998244353;
ll contr[N];
ll times[N];

int main() {
    contr[0] = 1;
    for(int i = 1; i < N; i++) {
        contr[i] = (contr[i-1] * 2) % MOD;
    }
    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;
    if(n > m) {
        string fillS(n - m, '0');
        b = fillS + b;
    }
    if(m > n) {
        string fillS(m - n, '0');
        a = fillS + a;
    }
    n = m = max(m, n);
    memset(times, 0, sizeof(times));
    for(int i = 0; i < n; i++) {
        if(b[i] == '1') times[i] = 1;
        if(i > 0) times[i] += times[i-1];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int pot = (n - 1) - i;
        if(a[i] == '1')
            ans += (contr[pot] * times[i]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}