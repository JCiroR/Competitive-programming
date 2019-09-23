#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll limit = 1e5 + 1;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    
    if(n % 2 == 0) {
        cout << n / 2 << endl;
        return 0;
    }
    for(int i = 3; i <= n && i <= limit; i++) {
        if(n % i == 0) {
            n -= i;
            cout << ((n / 2) + 1) << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}