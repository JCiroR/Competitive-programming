#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 100000;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

int values[200][3];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while(N != 1 && (PF * PF <= N)) {
        while(N % PF == 0) { N /= PF; factors.push_back(PF);}
        PF = primes[++PF_idx];
    }
    if(N != 1) factors.push_back(N);
    return factors;
}

int main() {
    sieve(10100);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int N, L;
        cin >> N >> L;
        vector<int> ans_v(L + 1, 0);
        set<int> choosenPrimes;
        for(int i = 0; i < L; i++) {
            cin >> values[i][0];
            vi aux = primeFactors(values[i][0]);
            choosenPrimes.insert(aux.begin(), aux.end());
            values[i][1] = aux[0];
            values[i][2] = aux[1];
        }
        map<int, char> decoder;
        char currChar = 'A';
        for(auto it = choosenPrimes.begin(); it != choosenPrimes.end(); it++)
            decoder[*it] = currChar++;
        int pivot;
        for(int i = 0; i + 1 < L; i++)
            if(values[i][0] != values[i + 1][0]) {
                pivot = i;
                if(values[i][1] != values[i+1][1] && values[i][1] != values[i+1][2])
                    ans_v[pivot] = values[i][1];
                else ans_v[pivot] = values[i][2];
                break;                
            }
        for(int i = pivot; i < L; i++)
            ans_v[i + 1] = values[i][0] / ans_v[i];
        for(int i = pivot - 1; i >= 0; i--)
            ans_v[i] = values[i][0] / ans_v[i + 1];
        string ans = "";
        for(int i = 0; i < ans_v.size(); i++)
            ans.push_back(decoder[ans_v[i]]);     
        cout << "Case #" << t << ": " << ans << endl;
    }
}