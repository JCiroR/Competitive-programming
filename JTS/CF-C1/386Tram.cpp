#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

 int s, x1, x2, t1, t2, p, d;

int getDis(int obj) {
    int dis = 0;
    while(obj != p) {
        if(p == 0 || p == s) d *= -1;        
        p += d;
        dis++;
    }
    return dis;
 }

int main() {   
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    int walk = abs(x1 - x2) * t2;
    int tram = (getDis(x1) + getDis(x2)) * t1;
    cout << min(walk, tram) << endl;    
}