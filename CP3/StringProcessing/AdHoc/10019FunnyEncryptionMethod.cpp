#include <string>
#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    while(N--) {
        string number;
        cin >> number;
        int dec = stoi(number, nullptr, 10);
        int hex = stoi(number, nullptr, 16);
        int b1 = 0, b2 = 0;
        for(int i = 0; i < 30; i++) {
            if(dec & (1 << i)) b1++;
            if(hex & (1 << i)) b2++;
        }
        cout << b1 << " " << b2 << endl;
    }
    
    return 0;
}