#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int main(void) {
    ll n, k;
    cin >> n >> k;
    if(n == 1) {
        cout << "Yes\n";
        return 0;
    }
    if(n <= k) {
        cout << "No\n";
        return 0;
    }   
    if(k == 1) cout << "Yes\n";
    else {
        int b = n  / k;
        int res = n % k;
        if(res == k - 1 && (b % (k - 1) == k - 2)) cout << "Yes\n";
        else cout << "No\n";
    }    
}