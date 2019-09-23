#include <iostream>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    int req = (t * n * k)/100;
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << " ";
        if(req >= k) {
            req -= k;
            cout << k;
        } else if(req > 0) {
            cout << req;
            req = 0;
        } else cout << 0;
    }   
    cout << endl;
}