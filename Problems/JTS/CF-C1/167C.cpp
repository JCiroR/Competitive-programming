#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    ll maxH = a[0];
    while(m--) {
        ll wi, hi;
        cin >> wi >> hi;
        cout << (maxH = max(a[wi - 1], maxH)) << '\n';
        maxH += hi;           
    }
}