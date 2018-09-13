#include <iostream>

using namespace std;

int powers[22];

int main(void) {
    powers[0] = 1;
    for(int i = 1; i < 22; i++)
        powers[i] = 2 * powers[i-1];

    int n;
    while(cin >> n && (n)) {
        if(n == 1){     
            cout << 1 << endl;
            continue;
        }
        for(int i = 0; i < 22; i++) {
            if(n <= powers[i]) {
                cout << (n - powers[i - 1]) * 2 << endl;
                break;
            }
        }
    }
    
    return 0;
}