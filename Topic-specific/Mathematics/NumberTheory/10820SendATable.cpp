#include <bitset>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 50010;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
ll answ[MAXN];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i<= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j+= i)
                bs[j] = 0;
            primes.push_back((int) i);
        }
}

ll eulerPhi(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while(N != 1 && (PF* PF <= N)) {
        if(N % PF == 0) ans -= ans/PF;
        while(N % PF == 0) N/= PF;
        PF = primes[++PF_idx];
    }
    if(N!=1) ans -= ans/N;
    return ans;
}

int main(void) {
    sieve(300);
    answ[1] = 1;
    for(ll i = 2;i <= 50000; i++)
        answ[i] = answ[i - 1] + eulerPhi(i) * 2;
    int n;
    while(scanf("%d", &n) && (n))
        printf("%lld\n", answ[n]);
    return 0;
}