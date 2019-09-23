#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 100010;

int l[MAXN];
int k[MAXN];

vector<ll> pot;

int main() {
    int n, f;
    ll ans = 0;
    cin >> n >> f;
    for(int i = 0; i < n; i++) {
        cin >> k[i] >> l[i];
        if(k[i] == 0) continue;
        if(l[i] <= k[i]) ans += l[i];
        else {
            ans += k[i];
            pot.push_back(min(l[i] - k[i], k[i]));
        }
    }
    sort(pot.begin(), pot.end(), greater<ll>());
    for(int i = 0; i < f && i < pot.size(); i++) ans += pot[i];
    cout << ans << endl;
}