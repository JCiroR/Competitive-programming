#include <iostream>

using namespace std;

int main(void) {
    int n;
    while(cin >> n && n) {
        long long nimSum = 0;
        long long curr;
        for(int i = 0; i < n; i++) {
            cin >> curr;
            nimSum ^= curr;
        }
        if(nimSum == 0) cout << "No\n";
        else cout << "Yes\n";
     }
}