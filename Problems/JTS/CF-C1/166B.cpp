#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1e5 + 100;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

int mat[510][510];

void sieve(ll upperbound) {
    _sieve_size = upperbound +1 ;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size ; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll n) {
    return bs[n];
}

int main() {
    sieve(100040);
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int ind = lower_bound(primes.begin(), primes.end(), mat[i][j]) - primes.begin();
            int cost = 100000000;
            if(ind < primes.size()) {
                cost = min(cost, abs(mat[i][j] - primes[ind]));
            }
            mat[i][j] = cost;
        }
    ll ans = 1LL<<60;
    for(int i = 0; i < n; i++)  {
        ll acum = 0;
        for(int j = 0; j < m; j++)
            acum += mat[i][j];
        ans = min(ans, acum);
    }

    for(int i = 0; i < m; i++) {
        ll acum = 0;
        for(int j = 0; j < n; j++)
            acum += mat[j][i];
        ans = min(ans, acum);
    }
    cout << ans << endl;
}