#include <iostream>

using namespace std;

int main(void) {
    long long a, b, temp;
    cin >> a >> b;
    if(a == 0) a++;
    long long times = b - a;
    
    if(times >= 5) cout << 0 << endl;
    else {
        int curr = 1;
        for(; times > 0; times--, b--) {
            curr = ((curr % 10)* (b % 10)) % 10;
        }
        cout << curr << endl;
    }

    return 0;
}