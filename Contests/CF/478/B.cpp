#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 15;
ll a[MAXN], b[MAXN];

void reset() {
    for(int i = 0; i < 14; i++)
        b[i] = a[i];
}

ll check() {
    ll ans = 0;
    for(int i = 0; i < 14; i++) {
        if(b[i] % 2 == 0) ans += b[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 14; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll ans = 0;
    for(int i = 0; i < 14; i++) {
        if(a[i] == 0) continue;
        ll num = b[i];
        b[i] = 0;
        ll t = num/14;
        for(int j = (i + 1)%14, lim = 0; lim < 14; lim++) {
            b[j] += t;            
            j++;
            j %= 14;
        }
        num -= t * 14;
        for(int j = (i + 1)%14; num > 0; j = (j+1)%14) {
            b[j]++;
            num--;
        }
        ans = max(ans, check());
        reset();
    }
    cout << ans << endl;
}