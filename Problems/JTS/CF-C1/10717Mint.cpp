#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, t, tab[11], coin[51];
ll below[11], above[11];

ll gcd(ll a, ll b) { return b == 0? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main() {
    while(scanf("%d %d", &n, &t) == 2 && (n || t)) {
        for(int i = 0; i < n; i++) scanf("%d", &coin[i]);
        for(int i = 0; i < t; i++) scanf("%d", &tab[i]);
        fill(below, below + 11, -1);
        fill(above, above + 11, INT_MAX);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ll first = lcm(coin[i], coin[j]);
                for(int k = j + 1; k < n; k++) {
                    ll second = lcm(first, coin[k]);
                    for(int l = k + 1; l < n; l++) {
                        ll third = lcm(second, coin[l]);
                        for(int m = 0; m < t; m++) {
                            ll times = tab[m] / third;
                            if(third * times == tab[m]) {
                                below[m] = above[m] = tab[m];
                            } else {
                                below[m] = max(below[m], third * times);                            
                                above[m] = min(above[m], third * (times + 1));
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < t; i++)
            printf("%lld %lld\n", below[i], above[i]);        
    }
}
