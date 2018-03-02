#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, y;
    cin >> x >> y;
    if(y == 0) {cout << "No" << endl; return 0;}
    if(y == 1 && x != 0) {cout << "No" << endl; return 0;}
    x-= y - 1;
    if(x >= 0 && x % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    
}