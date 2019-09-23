#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, b;

int main() {
    cin >> n >> m >> a >> b;
    a--, b--;          
    ll aC = a % m, aR = a / m;
    ll bC = b % m, bR = b / m;
    ll ans;
    if(aR == bR) ans = 1;
    else if(aC == 0 && bC == m - 1 || aC == 0 && b == n-1) ans = 1;
    else if(aC == bC + 1 || aC == 0 || bC == m-1 || b == n - 1 || aR == bR - 1) ans = 2;
    else ans = 3;
    cout << ans << endl;
}