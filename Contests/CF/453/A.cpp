#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int a1, b1, a2 = 0, b2 = 0;
    
    bool possible = false;
    for(int i = 0; i < n; i++) {
        cin >> a1 >> b1;    
        if(b2 < a1) break;
        if(b1 >= m) { 
            possible = true;
            break;
        }
        b2 = max(b1, b2);
    }

    (possible)? cout << "YES\n": cout << "NO\n";
    return 0;
}