#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

const int maxn = 1e5 * 2 + 10;
ll a[maxn];
int n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = -1, r = n;
    ll ans = 0, lsum = 0, rsum = 0;    
    while(l < r) {
        // cout << lsum << " " << rsum << endl;
        if(lsum == rsum) ans = max(ans, lsum);
        if(lsum <= rsum) {
            l++;
            if(l < r) lsum += a[l];
        } else {
            r--;
            if(l < r) rsum += a[r];
        }
    }
    cout << ans << endl;
}