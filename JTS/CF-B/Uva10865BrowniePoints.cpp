#include <cstring>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 200000;

typedef pair<int,int> ii;
vector<ii> brownies;

int main() {
    int n;
    brownies.reserve(MAXN);
    while(cin >> n && n != 0) {
        brownies.clear();
        int xi, yi, xcent, ycent;
        for(int i = 1; i <= n; i++) {
            cin >> xi >> yi;
            brownies.push_back(make_pair(xi, yi));
            if(i == (n/2 + 1)) {
                xcent = xi; 
                ycent = yi;        
            }
        }
        int stan = 0, ollie = 0; 
        for(int i = 0; i < n; i++) {
            xi = brownies[i].first;
            yi = brownies[i].second;
            if(xi < xcent && yi > ycent) ollie++;
            if(xi < xcent && yi < ycent) stan++;
            if(xi > xcent && yi > ycent) stan++;
            if(xi > xcent && yi < ycent) ollie++;        
        }
        cout << stan << " " << ollie << endl;
    }
}
