#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;
typedef long long ll;

const int MAXN = 2 * 1e5 + 10;
int a[MAXN], b[MAXN], n, k;
pair<int, int> c[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++) {
        c[i] = make_pair(b[i] - a[i], i);
    }
    sort(c, c + n,  greater<pair<int, int> >());
    ll ans = 0;
    for(int i = 0; i < k; i++) ans += a[c[i].second];
    for(int i = k; i < n; i++) {
        int ind = c[i].second;
        ans += min(b[ind], a[ind]);
    }
    cout << ans << endl;
}