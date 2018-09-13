#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 20;
ll a[N], n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    ll bef = 0, lin = 0;
    for(int i = 0; i < n; i++)
    {
        lin += a[i];
        ll curr = lin / m;
        if(i > 0) cout << " ";
        cout << curr - bef;
        bef = curr;
    }
    cout << endl;
}