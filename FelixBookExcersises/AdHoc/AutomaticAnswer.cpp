#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

int main(void) {
    int testCases, n;
    cin >> testCases;
    while(testCases--) {
        cin >> n;
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n /= 10;
        cout << abs(n % 10) << "\n";
    }
    return 0;
}