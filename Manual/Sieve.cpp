#include <bitset>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 10000001;

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
    if(n <= _sieve_size) return bs[n];
    for(int i = 0; i < primes.size(); i++)
        if(n % primes[i] == 0) return false;
    return true;
} 

vi primeFactors(ll N) {
  vi factors;                   
  ll PF_idx = 0, PF = primes[PF_idx] 
  while (N != 1 && (PF * PF <= N)) {   
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }   
    PF = primes[++PF_idx];                           
  }
  if (N != 1) factors.push_back(N);     // special case if N is actually a prime
  return factors;         // if pf exceeds 32-bit integer, you have to change vi
}

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);         // formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);        // last one
  return ans;
}

ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;             // start from ans = N
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;                // only count unique factor
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;                                     // last factor
  return ans;
}

int main(void) {
    sieve(10000000);
    printf("%d\n", isPrime(2147483647));
}