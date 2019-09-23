#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

long sumOfDigits(long n) {
    n = abs(n);
    long sum = 0;
    while(n > 9) {
        sum += n % 10;
        n /= 10;
    }
    sum += n;
    return sum;
}

int main(void) {
    long n, sum;
    while(cin >> n) {
        if(n == 0) break;
        sum = sumOfDigits(n);
        while(sum > 9) sum = sumOfDigits(sum);
        cout << sum << "\n";
    }
    return 0;
}