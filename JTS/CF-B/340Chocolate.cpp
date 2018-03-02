#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n, zeroes = 0, temp;
    bool nut = false;
    cin >> n;
    ll ans = 0;
    for(int i  = 1; i <= n; i++) {
        cin >> temp;
        if(nut) {
            if(temp == 0) zeroes++;
            else {
                ans *= (1 + zeroes);
                zeroes = 0;
            }
        } else if(temp == 1) {
            ans = 1;
            nut = true;
        }
    }
    cout << ans << endl;
}