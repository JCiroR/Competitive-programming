#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long x, max = 1;
    cin >> x;
    long long temp = x;
    for(long long i = 2; i*i <= x; i++) {    
        if(x % i == 0 && temp >= i && temp % i == 0) {
            max *= i;
            while(temp % i == 0) temp /= i;
        }
    }
    max *= temp;    
    cout << max << endl;
}