#include <bitset>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std; 
typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1010;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
int results[MAXN];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size;i++)
        if(bs[i]) {
            for(ll j = i*i; j<= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], answ = 1;
    while(N != 1 && (PF*PF <= N)) {
        ll power = 0;
        while(N % PF == 0) { N /= PF; power++;}
        answ *= ((ll)pow((double)PF, power + 1.0) - 1) /(PF - 1);
        PF = primes[++PF_idx];
    }
    if(N != 1) answ *=((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return answ;
}

int main(void) {
    sieve(1001);
    memset(results, -1, sizeof(results));
    ll temp;
    for(int i = 1; i <= 1000; i++) {
        temp = sumDiv(i);
        if(temp <= 1000) results[temp] = i;
    }
    int q, cases = 0;
    while(scanf("%d", &q) && (q)) {
        printf("Case %d: %d\n", ++cases, results[q]);
    }
    return 0; 
}