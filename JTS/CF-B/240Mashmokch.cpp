#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double a, b, w;    
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> w;
        if(i) cout << " ";
        cout << (int)(w - (floor(w * a/b) * b / a));
    }
    cout << endl;
}