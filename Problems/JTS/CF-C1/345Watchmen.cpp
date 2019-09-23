#include <utility>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> inX, inY;
    map<pair<int,int> , int> same;
    long long ans = 0;
    int x, y;
    while(n--) {
        cin >> x >> y;
        pair<int,int> p = make_pair(x, y);
        if(same.count(p) > 0) {
            ans -= same[p];
            same[p] += 1;
        } else same[p] = 1;

        if(inX.count(x) > 0) {
            ans += inX[x];
            inX[x] += 1;
        } else inX[x] = 1;
           
        if(inY.count(y) > 0) {
            ans += inY[y];
            inY[y] += 1;
        } else inY[y] = 1;                
    }        
    cout << ans << endl;
}

