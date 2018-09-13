#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map<int, ll> um;
unordered_map<int, ll> ump;
int n, m, a[(int)2e5 + 10], ind;

int main() {
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == m) ind = i;
    }
    ll ans = 1;
    int diff = 0;
    for(int i = ind-1; i >= 0; i--) {
        if(a[i] < m) diff--;
        else if(a[i] > m) diff++;
        if((ind - i + 1) % 2 == 0) {
            if(diff == 1) ans++;
            um[diff]++;
        } else {
            if(diff == 0) ans++;
            ump[diff]++;
        }
    }
    diff = 0;
    for(int i = ind + 1; i < n; i++) {
        int bef = ans;
        if(a[i] < m) diff--;
        else if(a[i] > m) diff++;
        ll merg = 0;
        if((i - ind + 1) % 2 == 0) {
            if(diff == 1) ans++;
            if(ump.count(1-diff)) merg += ump[1-diff];
            if(um.count(-diff)) merg += um[-diff];
        } else {
            if(diff == 0) ans++;
            if(ump.count(-diff)) merg += ump[-diff];
            if(um.count(1-diff)) merg += um[1-diff];
        }
        ans += merg;
    }
    printf("%I64d\n", ans);
}