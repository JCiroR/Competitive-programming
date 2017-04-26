#include <iostream>

using namespace std;

int main(void) {
    int testNum, n, k;
    cin >> testNum;
    while(testNum--) {
        cin >> n >> k;
        cout << (k ^ (k >> 1)) << "\n";
    }
    return 0;
}