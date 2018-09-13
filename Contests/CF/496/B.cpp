#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s, t;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    int ans = s.size() + t.size();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i = 0; i < min(s.size(), t.size()); i++){
        if(s[i] == t[i]) ans -= 2;
        else break;
    }
    cout << ans << endl;
}