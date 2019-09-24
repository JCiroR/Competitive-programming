#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 10 + 1e6;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll n) {    
    return bs[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve((ll)1e6);
    int n; cin >> n;
    double temp;
    while(n--) {
        cin >> temp;
        if(temp == 1.0) {
            cout << "NO\n";
            continue;
        }
        ll sq = sqrt(temp);
        if(sq*sq == temp && isPrime(sq)) cout << "YES\n";
        else cout << "NO\n";
    }
}