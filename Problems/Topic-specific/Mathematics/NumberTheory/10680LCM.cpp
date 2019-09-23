#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1000002;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
ll powers[100000];


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

int main(void) {
    sieve(1000000);
    ll n;
    while(scanf("%lld", &n) && (n)) {
        if(n == 1) { printf("1\n"); continue;}
        memset(powers, 0, sizeof(powers));

        for(int i = 0; i < primes.size() && primes[i] <= n; i++) {
            ll p = (ll)primes[i], temp = p;
            while(temp <= n) {
                temp *= p;
            }
            if(temp > n) temp /= p;
            powers[i] = temp;
        }

        if(powers[0] > 0 && powers[2] > 0) {
            ll temp = powers[0] * powers[2];
            while(temp % 10 == 0) temp /= 10;
            powers[0] = temp;
            powers[2] = 1;
        }
        int answ = 1;
        for(int i = 0; i < primes.size() && primes[i] <= n; i++) {           
            answ %= 10;
            answ = ((answ % 10) * (powers[i] % 10)) % 10;    
        }
        printf("%d\n", answ);
    }
    return 0;
}