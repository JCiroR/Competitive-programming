#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1e6 + 10;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
int a, b, k;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.pb((int)i);
        }
}

int main() {
    sieve(MAXN - 9);
    scanf("%d%d%d", &a, &b, &k);
    int left = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
    int right = upper_bound(primes.begin(), primes.end(), b) - primes.begin();
    if(right - left + 1 < k) printf("-1\n");
    else {
        int furthest = a, ans = -1;
        for(int i = left; i + k - 1  < right; i++) {
            ans = max(ans, primes[i+k-1] - furthest + 1);
            furthest = primes[i] + 1;
        }
        furthest = b;
        for(int i = right - 1; i - k + 1 >= left; i--) {
            ans = max(ans, furthest - primes[i-k+1] + 1);
            furthest = primes[i] - 1;
        }
        printf("%d\n", ans);
    }
}

