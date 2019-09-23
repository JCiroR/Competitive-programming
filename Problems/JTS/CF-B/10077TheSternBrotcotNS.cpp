#include <iostream>
#include <utility>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> frac;

bool above(frac f1, frac f2) {
    if(f1.second == 0 || f2.first == 0) return true;
    else if(f1.first == 0 || f2.second == 0) return false;
    else return ((double)f1.first)/((double)f1.second) > ((double)f2.first)/((double)f2.second);
}

int main() {
    ll n, d;
    while(cin >> n >> d) {
        if(n == 1 && d == 1) break;
        frac left(0, 1), right(1, 0), curr(1, 1), target(n, d);
        string ans = "";
        while(target != curr) {
            if(above(curr, target)) {
                ans += 'L';
                right = curr;
                curr.first += left.first;
                curr.second += left.second;
            } else {
                ans += 'R';
                left = curr;
                curr.first += right.first;
                curr.second += right.second;
            }
        }
        cout << ans << endl;
    }
}