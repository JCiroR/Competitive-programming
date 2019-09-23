#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 6000;

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

const int maxN = 3 * 1e5 + 10;
const int maxK = 2*1e7 + 10;
int a[maxN];
int times[maxK];

void process(int num) {
    for(int i = 0; i < primes.size() ; i++) {
        int p = primes[i];
        if(num % p == 0) {
            int curr = p;
            while(num % p == 0) {
                times[curr]++;
                num /= p;
                curr *= p;
            }
        }
    }
    if(num > 1) times[num]++;
}


int main(void) {
    sieve(5000);
    memset(times, 0, sizeof times);
    int n;
    scanf("%d", &n);
    int prev = -1;
    bool allEqual = true;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        process(a[i]);
        if(prev != -1) {
            if(a[i] != prev) allEqual = false;
        }
        prev = a[i];
    }
    if(allEqual) {
        printf("-1\n");
        return 0;
    }
    
    int ans = n - 1;
    for(int i = 0; i < maxK; i++) {
        if(times[i] > 1 && times[i] < n) {
            int pos = n - times[i];
            ans = min(ans, pos);
        }
    }
    printf("%d\n", ans);
}