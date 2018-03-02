#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main(void) {
    int T;
    ll a, b;
    cin >> T;
    int cT = 1;
    while(T--) {
        cin >> a >> b;
        ll answ;
        if(a == b) answ = 2;
        else {
            ll temp = gcd(a, b);
            answ = a/temp + b/temp;
        }
        cout << "Case " << cT <<": " << answ << endl;
        cT++;
    }
    return 0;
}