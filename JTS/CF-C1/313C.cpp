#include <iostream>

using namespace std;

int main() {
    long long c1,c2,c3,c4,c5,c6;
    cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    cout << (c1 + c2 + c3)*(c1 + c2 + c3) - c1 * c1 - c3 * c3 - c5 * c5 << endl;
}