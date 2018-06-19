#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll n, m; 
    cin >> n >> m;
    ll r1 = m - 1, r2 = n - m;
    if(r1 >= r2) cout << max(1LL, m - 1LL) << endl;
    else cout << min(n, m + 1) << endl;

}