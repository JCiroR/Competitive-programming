#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int U, D, L, R;
    U = D = L = R = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') U++;
        if(s[i] == 'D') D++;
        if(s[i] == 'L') L++;
        if(s[i] == 'R') R++;
    }
    cout << min(U,D) * 2 + min(L,R) * 2 << endl;

}