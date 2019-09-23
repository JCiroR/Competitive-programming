#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while(N != 1 && (PF * PF <= N)) {
        ll power = 0;
        while(N % PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if(N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

int main() {
    sieve(70000);
    int n;
    printf("PERFECTION OUTPUT\n");
    while(cin >> n && n) {
        printf("%5d  ", n);
        ll ans = sumDiv(n) - n;
        if(bs[n]) ans = 1;
        if(n == 1) ans = 0;
        
        if(ans == n) printf("PERFECT");
        else if(ans > n) printf("ABUNDANT");
        else printf("DEFICIENT");
        printf("\n");
    }
    printf("END OF OUTPUT\n");
}