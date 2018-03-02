#include <iostream>

using namespace std;

typedef long long ll;

ll fast_exp(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) %p;
    }
    return res;
}

int main(void) {
    ll B, P, M;
    while(cin >> B >> P >> M) {
        cout << fast_exp(B, P, M) << endl;
    }
    return 0;
}