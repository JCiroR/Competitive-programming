#include <bitset>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 10000;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
ll n;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
    cin >> n;
    sieve(n);
    ll ans = 0;
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] > n) break;
        ll temp = primes[i];
        while(temp <= n) {
            ans++;
            temp *= primes[i];
        }
    }
    cout << ans << endl;
    bool first = true;
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] > n) break;
        ll temp = primes[i];
        while(temp <= n) {
            if(!first) printf(" ");
            printf("%I64d", temp);
            first = false;
            temp *= primes[i];
        }
    }
    printf("\n");
}