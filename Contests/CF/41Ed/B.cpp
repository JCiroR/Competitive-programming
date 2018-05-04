#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
int a[MAXN], t[MAXN];

int main(void) {
    int n, k; scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &t[i]);
    ll ans = 0, maX = -1, curr = 0;
    //cout << "curr " << "maX " << "ans" << endl;
    for(int i = 0; i < n; i++) {
        if(t[i]) ans += a[i];
        else curr += a[i];
        if(i >= k - 1) {
            if(i - k >= 0 && !t[i - k]) curr -= a[i - k];
            maX = max(maX, curr);
        }    
        //cout << i << " " << curr << " " << maX << " " << ans << endl;
    }
    if(maX > -1) cout << ans + maX << endl;
    else cout << ans << endl;
}