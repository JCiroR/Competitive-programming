#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
const int MAXN = 1e5;

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
    if(n < _sieve_size) return bs[n];
    for(int i = 0; i < primes.size(); i++)
        if(n % primes[i] == 0) return false;
    return true;
}

int main() {
    sieve(70000);
    ll n;
    while(cin >> n && n) {
        unsigned long long perf = ((1LL<<n) - 1LL) * (1LL<<(n-1LL));
        if(isPrime(((1<<n) - 1)))
            cout << "Perfect: " << perf << "!\n";
        else if(isPrime(n))
            cout << "Given number is prime. But, NO perfect number is available.\n";
        else
            cout << "Given number is NOT prime! NO perfect number is available.\n";
    }
}