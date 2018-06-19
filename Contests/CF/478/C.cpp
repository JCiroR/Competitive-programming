#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5  + 20;
ll acum[MAXN], a[MAXN];
int n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        acum[i] = a[i];
        if(i > 0) acum[i] += acum[i - 1];
    }

    int start = 0, done = 0;
    while(q--) {
        ll k; 
        cin >> k;
        k += done, done = 0;
        if(start > 0) k += acum[start - 1];
        int lim = upper_bound(acum, acum + n, k) - acum;

        if(lim == n || n - lim <= 0) { 
            cout << n << endl;
            start = 0;
        } else {
            cout << n - lim << endl;
            if(lim > 0) k -= acum[lim - 1];
            done = k;
            start = lim;
        }
    }
}