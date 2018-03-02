#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstido>

using namespace std;
const int MAXN = 2*1000010;
typedef long long ll;

ll n, sum[MAXN];

ll getSum(ll t) {
    ll ans = sum[n - 1];    
    if(t < n) ans -= sum[n - 1 - t];
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%I64d", &sum[i]);    
    sort(sum, sum + n);
    for(int i = 1; i < n; i++) sum[i] += sum[i - 1];
    ll ans = 0, layer = n; 
    while(layer > 0) {        
        ans += getSum(layer);
        layer /= 4L;
    }
    cout << ans << endl;
}
