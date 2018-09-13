#include <bitset>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 33005;

ll _sieve_size;
bitset<MAXN> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            for(ll j = i*i; j <= _sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

vector<pair<int,int> > getFactors(int N) {
    vector<pair<int,int> > answ;
    int PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= N) {
        if(N % PF == 0) {
            pair<int,int> p = make_pair(PF, 0);
            while(N % PF == 0) {
                N /= PF;
                p.second += 1;
            }
            answ.push_back(p);
        }
        PF = primes[++PF_idx];
    }
    if(N != 1) answ.push_back(make_pair(N, 1));
    return answ;
}

int main(void) {
    sieve(33000);
    string l1;
    while(getline(cin, l1)) {
        stringstream ss;
        ss << l1;
        int factor, p; 
        int number = 1;
        bool zero = false;
        while(ss >> factor) {
            if(factor == 0) {
                zero = true; 
                break;
            }
            ss >> p;
            number *= (int)pow((double)factor, (double)p);
        }
        if(zero) {
            break;
        }
        number--;
        vector<pair<int,int> > factors = getFactors(number);
        cout << factors[factors.size() - 1].first << " " << factors[factors.size() - 1].second;
        for(int i = factors.size() - 2 ; i >= 0; i--) {
            cout << " " << factors[i].first << " " << factors[i].second;
        }
        cout << endl;
    }
    return 0;
}