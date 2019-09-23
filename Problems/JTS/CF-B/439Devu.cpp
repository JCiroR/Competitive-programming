#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> chaps;

int main() {
    ll n, x;
    cin >> n >> x;
    chaps.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> chaps[i];
    sort(chaps.begin(), chaps.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += chaps[i] * x;
        if(x > 1) x--;
    }
    cout << ans << endl;
}
