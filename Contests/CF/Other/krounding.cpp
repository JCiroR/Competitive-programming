#include <iostream>
#include <algorithm>

using namespace std;

long long pow(long long base, int exp) {
    long long res = 1;
    for(int i = exp; i > 0; i--) {
        res *= base;
    }
    return res;
}

int timesDivisibleBy(long long n, int numb) {
    int times = 0;
    while(n >= numb) {
        if(n % numb == 0) {
            times++; 
            n/= numb;
        } else break;
    }
    return times;
}

int main(void) {
    long long n; int k;
    while(cin >> n >> k) {
        if(k != 0) {
            int nOf2 = max(0, k - timesDivisibleBy(n, 2));
            int nOf5 = max(0, k - timesDivisibleBy(n, 5));
            long long fact = pow(2, nOf2) * pow(5, nOf5);
            cout << n * fact << endl;
        } else cout << n << endl;
    }
    return 0;
}