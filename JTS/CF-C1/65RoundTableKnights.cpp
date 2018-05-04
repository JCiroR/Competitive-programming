#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 1010;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;
int table[100010], n;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = bs[0];
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j += i)
                bs[j] = 0;
            if(i != 2) primes.push_back(i);
            if(i == 3) primes.push_back(4);
        }
}

bool check(int k) {
    if(k < 3) return false;
    int d = n/k;
    for(int i = 0; i < d; i++) {
        int curr = i;
        bool correct = true;
        for(int j = 0; j < k; j++) {
            if(table[curr % n] == 0) correct = false;
            curr += d;
        }
        if(correct) return true;
    }
    return false;
}

int main() {
    sieve(1000);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> table[i];
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] < 3) continue;
        if(primes[i] > n) break;
        if(n % primes[i] == 0 && check(primes[i])) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}