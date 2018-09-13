#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

int main(void) {
    long num, a, b, t;
    while(cin >> num) {
        if(num == 0) break;
         a = 0;
         b = 0;
         while((t = num & -num)) {
            num = num ^ t;
            a = a | t;
            t = num & (-num);
            num = num ^ t;
            b = b | t;
         }
         cout << a << " " << b << "\n";
    }
    return 0;
}