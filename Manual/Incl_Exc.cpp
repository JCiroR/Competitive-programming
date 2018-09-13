#include <iostream>
using namespace std;

typedef long long ll;

ll intersect(ll A, ll B) {

}

ll getValue(int index) {

}

ll getCard(ll subset) {

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
        //fourth parameter is def value
        ans += (intersect_n(n, -1, i, 1) * sign);
        sign *= -1;
    }
    return ans;
}