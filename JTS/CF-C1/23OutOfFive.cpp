#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iterator>

using namespace std;
typedef long long ll;
const int P = 1, M = 2, T = 3;

ll eval(ll a, ll b, int op) {
		if(op == P) return a + b;
    else if(op == M) return a - b;
    else if(op == T) return a * b;
		else return -1;
}

bool check(ll a1, ll a2, ll a3, ll a4, ll a5) {
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++)
        for(int k = 1; k <= 3; k++) for(int l = 1; l <= 3; l++) {
            ll res = eval(a1, a2, i);
            res = eval(res, a3, j);
            res = eval(res, a4, k);
            res = eval(res, a5, l);
            if(res == 23) return true;
        }
    return false;
}

int main() {
    ll opt[5];
    while(scanf("%lld%lld%lld%lld%lld", &opt[0], &opt[1], &opt[2], &opt[3], &opt[4]) == 5) {
        if(!(opt[0] || opt[1] || opt[2] || opt[3] || opt[4])) break;
        sort(begin(opt), end(opt));
        bool found = false;
        do {
            if(check(opt[0], opt[1], opt[2], opt[3], opt[4])) {
                found = true;
                break;
            }
        } while(next_permutation(begin(opt), end(opt)));
        if(found) printf("Possible\n");
        else printf("Impossible\n");
    }
}

