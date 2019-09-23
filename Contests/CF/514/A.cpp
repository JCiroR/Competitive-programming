#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 1e5 + 1;
ll t[N], l[N];
ll n, L, a;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> L >> a;
    for(int i = 0; i  < n; i++)
        cin >> t[i] >> l[i];
    ll lastT = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (t[i] - lastT) / a;
        lastT = t[i] + l[i];
    }
    if(lastT < L) {
        ans += (L - lastT) / a;
    }
    cout << ans << endl;
}   