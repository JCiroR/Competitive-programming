#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll p = 1, ans = 1;
    while(p <= n) {
        if(n % p != 0) ans = max(ans, n/p + 1);
        p *= 3LL;
    }
    cout << ans << endl;
}