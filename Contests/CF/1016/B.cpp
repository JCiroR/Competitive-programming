#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 20;
int p[N];
int n, m, q;

int getAns(int l, int r) {
    // cout << "****" << endl;
    if((l > n - m) || (r - l + 1) < m) return 0;
    // cout << r - l + 1 << endl;
    // cout << l << "-" << r << endl;
    // cout << r - m + 1 << endl;
    // cout << l - 1 << endl;
    int ans = p[r-m+1];
    if((l-1) >= 0) ans -= p[l-1];
    // cout << "ans: " << ans << endl;
    // cout << "----" << endl;
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(p, 0, sizeof(p));
    string s, t;
    cin >> n >> m >> q >> s >> t;
    if(n >= m) {
        for(int i = 0; i <= n - m; i++) {
            bool match = true;
            for(int j = i; j <= i + m - 1; j++) {
                if(s[j] != t[j-i]) {
                    match = false;
                    break;
                }
            }
            p[i] = match;
        }
    }
    for(int i = 1; i < max(n, m); i++) {
        p[i] += p[i-1];
    }
    while(q--) {
        int l, r; 
        cin >> l >> r;
        l--, r--;
        cout << getAns(l, r) << endl;
    }
}