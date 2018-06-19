#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 1;
int a[MAXN], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    ll ans = 0, bef = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(a[i] >=  bef) ans += a[i];
            else {
                ans += bef;
                bef = a[i];
            }
        } else bef += a[i];
    }
    cout << ans << endl;
}
