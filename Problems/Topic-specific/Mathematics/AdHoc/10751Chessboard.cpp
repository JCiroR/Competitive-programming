#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        double answ;
        if(n >= 3) answ = (n - 2) * (n - 2) * sqrt(2) + n * n - (n - 2) * (n - 2);
        else if(n == 2) answ = 4.0;
        else if(n == 1) answ = 0.0;
        printf("%.3f\n", answ);
        if(T) printf("\n");
    }
}