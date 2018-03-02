#include <iostream>

using namespace std;

typedef long long ll;

ll lnzdigit(ll n, ll m) {
    if(n == 0 || m == 0) return 1;
    ll acum = 1;
    for(ll i = n; i >= n - m + 1; i--) {
        acum *= i;
        while(acum % 10 == 0) acum /= 10;
        acum %= 1000000000;
    }
    return acum % 10;
}


int main(void) {
    ll N, M;
    while(cin >> N >> M) {
        cout << lnzdigit(N,M) << endl;
    }
}