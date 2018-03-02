#include <iostream>

using namespace std;

int timesByTwo(long long n) {
    if(n == 0) return 0;
    int cont = 0;
    for(int i = 0; i < 31; i++) {
        if(! (n & (1 << i))) cont++;
        else break;
    }
    return cont;
}

int main(void) {
    long long number;
    while(cin >> number) {
        int operations = 0;
        while(number != 0) {;
            if(number == 1 || number == 3) number--;
            else if(number % 2 == 0) number /= 2;
            else if(timesByTwo(number + 1) > timesByTwo(number - 1)) number++;
            else number--;
            operations++;
        }
        cout << operations << endl;
    }
}