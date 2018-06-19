#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, b;
    while(cin >> n >> b && (n || b)) {
        ll ans = LONG_LONG_MAX;
        for(ll i = 2; i <= b; i++) {
            if(b % i == 0) {
                int times = 0;
                while(b % i == 0) {
                    b /= i;
                    times++;
                }
                ll currAns = 0, tmp = i;
                while(tmp <= n && tmp > 0) {
                    for(ll j = 1LL; n - tmp * j + 1LL > 0; j++) {
                        ll sum = n - tmp * j + 1LL;
                        currAns += (sum * (sum + 1LL))/2LL;                
                    }
                    tmp *= i;
                }
                ans = min(ans, currAns/times);                
            }
        }
        cout << ans << endl;
    }
}
