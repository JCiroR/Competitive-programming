#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int t = gcd(a,b), times = 0;
    a /= t, b/= t;
    while(a != 1) {
        if(a % 2 == 0) {
            a /= 2;
            times++;
        } else if(a % 3 == 0) {
            a /= 3;
            times++;
        } else if(a % 5 == 0) {
            a /= 5;
            times++;
        } else break;
    }
    while(b != 1) {
        if(b % 2 == 0) {
            b /= 2;
            times++;
        } else if(b % 3 == 0) {
            b /= 3;
            times++;
        } else if(b % 5 == 0) {
            b /= 5;
            times++;
        } else break;
    }
    if(a != b) cout << -1;
    else cout << times;
}