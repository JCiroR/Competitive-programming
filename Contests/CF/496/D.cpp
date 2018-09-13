#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
int a[4];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    s.reserve(2e5); 
    a[1] = a[2] = 0;
    
    cin >> s;
    int n = s.size(), ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int d = s[i] - '0';
        if(d % 3 == 0) {
            ans++;
            a[1] = a[2] = a[3] = sum = 0;
        } else {
            a[d % 3]++;
            a[3]++;
            sum += d;
            int mod = sum % 3;
            if(mod == 0) {
                ans++;
                a[1] = a[2] = a[3] = sum = 0;
            } else if(sum > 3) {
                bool pos = false;
                pos |= (mod == 1 && ((a[1] > 0 && a[3] > 1) || (a[2] > 1 && a[3] > 2)));
                pos |= (mod == 2 && ((a[1] > 1 && a[3] > 2) || (a[2] > 0 && a[3] > 1)));
                if(pos) {
                    ans++;
                    a[1] = a[2] = a[3] = sum = 0;
                }
            }
        }
    }
    cout << ans << endl;
}