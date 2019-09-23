#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, c = 0, ans = 0;
    cin >> n;
    for(ll x = 1; n - 2LL * x - c >= 0; x++)
    {
        c = (x * (x - 1))/2;
        ll r = n - 2LL * x;
        if(r % 3 == 0 &&  (r/3LL) >= c) {
            ans++;
            // cout << x << " " << n << " " << r << " " << c << " " <<  'Y' << endl;
        }// else cout << x << " " << n << " " << r << " " << c << " " << 'N' << endl;
    }
    cout << ans << endl;
} 