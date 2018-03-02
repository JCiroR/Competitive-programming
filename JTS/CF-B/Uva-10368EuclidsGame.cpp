#include <iostream>
#include <utility> //Swap in c++11
#include <algorithm> //In c++98

using namespace std; 

typedef long long ll;

bool solve(ll a,ll b) {
    if(a < b) swap(a, b);
    if(a % b == 0) return true;
    if(solve(b, a % b) && b * 2 > a) return false;
    return true;
}

int main(void) {
    ll a, b;
    while(cin >> a >> b && a && b) {
        if(solve(a,b)) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
}