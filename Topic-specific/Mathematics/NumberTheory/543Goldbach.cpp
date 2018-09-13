#include <bitset>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1000005;

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
            if(i != 2) primes.push_back((int)i);
        } 
}

bool isPrime(ll n) {
    if(n <= _sieve_size) return bs[n];
    for(int i = 0; i < primes.size(); i++)
        if(n % primes[i] == 0) return false;
    return true;
}

int main(void) {
    sieve(1000000);
    int n;
    while(scanf("%d", &n) == 1 && (n)) {
        int a, b;
        for(int i = 0; i < primes.size(); i++) {
            a = primes[i]; 
            b = n - a;
            if(isPrime(b)) {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
    return 0;
}