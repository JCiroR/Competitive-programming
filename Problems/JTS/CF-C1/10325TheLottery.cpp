/**
    Kind of an experiment
**/

#include <iostream>
using namespace std;
typedef long long ll;

int elements[16];
ll limit;

ll gcd(ll a, ll b) { return b == 0? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

ll intersect(ll A, ll B) {
    return lcm(A, B);
}

ll getValue(int index) {
    return elements[index];
}

ll getCard(ll subset) {
    return limit/subset;
}

ll intersect_n(int n, int from, int left, ll curr) {    
    // return null
    if(from >= n || left > n - from + 1 || left < 0) return 0;
    if(left == 0) {    
        // get and return cardinality
        return getCard(curr);
    } 
    ll ans = 0;
    for(int i = from + 1; i < n; i++) {
        ans += intersect_n(n, i, left-1, intersect(curr, getValue(i)));
    }
    return ans;
}

ll inclusion_exclusion(int n) {
    ll ans = 0, sign = 1;
    for(int i = 1; i <= n; i++) {
        ans += (intersect_n(n, -1, i, 1) * sign);
        sign = -1 * sign;
    }
    return ans;
}

int main() {
    int cN, cM;
    while(cin >> cN >> cM) {
        for(int i = 0; i < cM; i++) cin >> elements[i];
        limit = cN;
        ll ans = inclusion_exclusion(cM);
        cout << cN - ans << endl;
    }
}