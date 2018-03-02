#include <iostream>

using namespace std;

int main(void) {
    int cases; long a, b;
    cin >> cases;
    while(cases--) {
        cin >> a >> b;
        if(a > b) cout << ">" << "\n";
        else if(a < b) cout << "<" << "\n";
        else cout << "=" << "\n";
    }
    return 0;
}
