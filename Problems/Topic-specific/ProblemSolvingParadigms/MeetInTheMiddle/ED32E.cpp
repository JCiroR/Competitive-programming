#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
uint n, temp, m, a[37], ans = 0;
vector<uint> s;

int main(void) {
    s.reserve(140000);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = n / 2, r = n / 2;
    if(r + l != n) r++;
    int lim = (1 << l) - 1;
    while(lim) {
        uint sum = 0;
        for(int i = 0; i < l; i++)
            if(lim & (1 << i)) {
                sum += a[i];
                sum %= m;
            }
        ans = max(ans, sum);
        s.push_back(sum);
        lim--;
    }
    sort(s.begin(), s.end(), greater<uint>());
    lim = (1 << r) - 1;
    while(lim) {
        uint sum = 0;
        for(int i = 0; i < r; i++)
            if(lim & (1 << i)) {
                sum += a[l + i];
                sum %= m;
            }
        ans = max(ans, sum);
        uint up = m - sum;
        auto it = upper_bound(s.begin(), s.end(), up, greater<uint>());
        if(it != s.end()) 
            ans = max(ans, sum + *it);
        lim--;
    }
    cout << ans << endl;
    return 0;
}