#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    if(n <= y) {
        y -= n;
        if((1LL + y) * (1LL +  y) + n - 1 >= x) {
            cout << (1LL + y) << endl;            
            for(int i = 0; i < n - 1; i++) cout << 1 << endl;
        } else cout << -1 << endl;
    } else cout << -1 << endl;
}