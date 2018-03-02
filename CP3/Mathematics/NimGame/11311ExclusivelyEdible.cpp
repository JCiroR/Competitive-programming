#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int m, n, r, c;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n >> r >> c;
        int above = r, left = c, below = m-1-r, right = n-1-c;
        int nimSum = above^left^below^right;
        if(nimSum) cout << "Gretel\n";
        else cout << "Hansel\n";
    }
    return 0;
}