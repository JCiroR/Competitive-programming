#include <bitset>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 10000010;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

int main() {
    sieve(10000001);
    int n;
    while(scanf("%d", &n) == 1) {
        if(n < 8) printf("Impossible.\n");
        else {
            if(n&1) printf("2 3");
            else printf("2 2");
            n -= (4 + (n % 2));
            for(int i = 0; i < primes.size(); i++)
                if(bs[n - primes[i]]) {
                    printf(" %d %d\n", primes[i], n - primes[i]);
                    break;
                }             
        }
    }
}