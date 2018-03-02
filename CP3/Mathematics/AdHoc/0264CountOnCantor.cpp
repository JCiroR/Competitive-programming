#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
    int n;
    while(cin >> n) {
        int diag = 0, sum = 0;
        while(n > sum) {
            diag++;
            sum += diag;
        }
  
        int diff = sum - n, num, den;
        if(diag % 2 == 0) {
            num = diag - diff;
            den = 1 + diff;
        } else {
            num = 1 + diff;
            den = diag - diff;
        }
        printf("TERM %d IS %d/%d\n", n, num, den);
    }
}