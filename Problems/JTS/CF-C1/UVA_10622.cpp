#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll lim = 1LL << 32;
unordered_map<ll, int> ans;

int main() {
    ans.reserve(70000);
    for(int p = 2; p <= 32; p++) {
        for(ll i = 2; ; i++) {
            ll b = i;
            for(int j = 1; j < p; j++)
                b *= i;
            if(b > lim) break;
            ans[b] = p;
            if(p & 1) ans[-b] = p;
        }
    }
    ll n;
    while(scanf("%lld",&n) == 1 && n) {
        if(ans.count(n)) printf("%d", ans[n]);
        else printf("1");
        printf("\n");
    }
}