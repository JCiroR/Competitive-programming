#include <iostream>

using namespace std;

int main(void) {
    int a, b, testCases;
    cin >> testCases;
    while(testCases--) {
        cin >> a >> b;
        cout << (a/3) * (b/3) << endl;
    }
    return 0;
}