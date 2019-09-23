#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll fast_exp(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while(y > 0) {
        if(y&1) res = (res * x) % p;
        y = y>> 1;
        x = (x*x) % p;
    }
    return res;
}

int main(void) {
    int T;
    scanf("%d", &T);
    ll n,k;
    while(T--) {
        scanf("%lld %lld", &n, &k);
        int trailing = (int)pow(10, 2.0 + fmod(k * log10(n),1));
        int leading  = (int)fast_exp(n, k, 1000);
        printf("%d...%03d\n", trailing, leading);
    }
    return 0;
}