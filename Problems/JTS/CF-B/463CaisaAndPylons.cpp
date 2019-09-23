#include <iostream>

using namespace std;

int main(void) {
    int n, max = 0, temp;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        if(temp > max) max = temp;
    }
    cout << max << endl;
}