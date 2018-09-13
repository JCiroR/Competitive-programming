#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    int n;
    while(cin >> n && (n)) {
        int x = (n - 1960)/10 + 2;
        double sum = 0, lim = pow(2.0, (double)x);
        
        int fact = 1;
        while(true) {
            sum += log2((double)fact);
            if(sum > lim) {
                fact--;
                break;
            }
            fact++;
        }

        cout << fact << endl;
    }
    return 0;
}