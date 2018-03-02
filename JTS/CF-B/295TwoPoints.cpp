#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, clicks = 0;
    cin >> n >> m;
    while(m != n) {
        if(m < n) {
            clicks += n - m;
            m = n;
        } else if(m&1) {
            clicks++;
            m++;
        } else {
            clicks++;
            m /= 2;
        }
    }
    cout << clicks << endl;
}