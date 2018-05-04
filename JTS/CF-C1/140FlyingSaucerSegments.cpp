#include <iostream>

using namespace std;
typedef long long ll;

ll fast_exp(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while(y > 0) {
        if(y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    ll n, p; cin >> n >> p;
    ll ans = fast_exp(3LL, n, p);
    if(ans > 0) cout << (ans-1) % p;
    else cout << p - 1;
    cout << endl;
}