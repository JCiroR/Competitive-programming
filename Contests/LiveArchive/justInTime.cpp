#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int x;
    while(cin >> x) {
        if(x == 2) cout << 1 << endl;
        else if(x == 3) cout << x << endl;
        else cout << x - 1 << endl;
    }
    return 0;
}