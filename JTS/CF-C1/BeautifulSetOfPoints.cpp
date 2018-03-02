#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int lim = min(n, m);
    cout << lim + 1 << endl;
    for(int i = 0; i <= lim; i++) {
        cout << i << " " << lim - i << endl;
    }
}