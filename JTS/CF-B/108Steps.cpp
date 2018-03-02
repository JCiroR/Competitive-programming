#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    int n, m, xc, yc, k, dx, dy;
    cin >> n >> m >> xc >> yc >> k;
    ll steps = 0, xsteps, ysteps, limit;
    while(k--) {
        cin >> dx >> dy;
        if(dx > 0) xsteps = (n - xc) / dx;
        else if(dx < 0) xsteps = (xc - 1) / dx * -1;
        else xsteps = INT_MAX;

        if(dy > 0) ysteps = (m - yc) / dy;
        else if(dy < 0) ysteps = (yc - 1) / dy * -1 ;
        else ysteps = INT_MAX;
        limit = min(ysteps, xsteps);
        xc += limit * dx;
        yc += limit * dy;
        steps += limit;
    }
    cout << steps << endl;
    
}