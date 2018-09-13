#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 10000005;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j= i*i; j <= _sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

ll LPM(ll N) {
    int PF_idx = 0, c = 0;
    ll PF = (ll)primes[PF_idx], lpm = -1;
    while(N != 1 && (PF * PF <= N) PF_idx < primes.size()-1) {
        if(N % PF == 0) c++;
        while(N % PF == 0) {
            lpm = PF;
            N /= PF;
        }
        PF = (ll)primes[++PF_idx];
    }
    if(N != 1) { 
        c++;
        lpm = max(lpm, N);
    }
    if(c > 1) return lpm;
    else return -1;
}

int main(void) {
    sieve(10000000);
    ll d;
    while(scanf("%lld", &d) == 1 && (d)) {
        if(d < 0) d *= -1;
        ll answ = LPM(d);
        printf("%lld\n", answ);
    }
    return 0;
}