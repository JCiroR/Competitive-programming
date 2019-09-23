#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
vector<ll> aux[2];
int siz[2];
ll a[N];
set<ll> ans;

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    aux[0].clear();
    aux[1].clear();
    
    int v = 0;
    for(int i = 0; i < n; i++) {
        int prev = (v + 1) % 2;
        ll curr = a[i];
        aux[v].clear();
        aux[v].push_back(curr);
        ans.insert(curr);
        ll lastIns = curr;
        for(int j = 0; j < aux[prev].size(); j++) {
            ll newGcd = __gcd(aux[prev][j], curr);
            if(newGcd != lastIns) aux[v].push_back(newGcd);
            lastIns = newGcd;
            ans.insert(newGcd);
        }
        v = (v + 1) % 2;
    }
    printf("%lu\n", ans.size());
}
