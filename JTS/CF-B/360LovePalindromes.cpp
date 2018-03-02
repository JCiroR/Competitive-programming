#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    cout << a << b << endl;
}