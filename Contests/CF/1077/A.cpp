#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll pos = (k/2) * (a-b);
        if(k&1) pos += a;
        cout << pos << endl;
    }
}