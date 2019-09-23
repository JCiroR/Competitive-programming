#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;

ll a[MAXN];
int n, d;

int main() {
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    ll ans = 0, cD = 0;
    int l = 0;
    for(int r = 0; r < n; r++) {
        while(abs(a[r] - a[l]) > d)  l++;
        //cout << l << "-" << r << endl;
        ll count = r - l + 1;
        if(count < 3) continue;
        ans += ((count - 1) * (count - 2) / 2LL);        
    }
    printf("%I64d\n", ans);
}
