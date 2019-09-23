#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
const int MAXN = 100010;

int x[MAXN], y[MAXN], z[MAXN];
string s; 

bool check(int l, int r) {    
    if(r - l < 2) return true;
    int a,b,c;
    a = x[r] - x[l-1];
    b = y[r] - y[l-1];
    c = z[r] - z[l-1];
    if(abs(a-b) <= 1 && abs(a-c) <= 1 && abs(b-c) <= 1 && a > 0 && b > 0 && c > 0) return true;
    return false;
}

int main() {    
    x[0] = y[0] = z[0] = 0;
    cin >> s;
    for(int i = 1;i <= s.size(); i++) {
        x[i] = x[i-1], y[i] = y[i-1] , z[i] = z[i-1];
        if(s[i-1] == 'x') x[i]++;
        else if(s[i-1] == 'y') y[i]++;
        else if(s[i-1] == 'z') z[i]++;
    }

    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        if(check(l,r)) cout << "YES\n";
        else cout << "NO\n";        
    }    
}
