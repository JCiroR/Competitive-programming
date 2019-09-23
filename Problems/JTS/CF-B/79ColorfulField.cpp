#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m, k, t, x, y;
    cin >> n >> m >> k >> t;
    vector<int> waste;
    while(k--) {
        cin >> x >> y;
        waste.push_back((x-1) * m + y);
    }
    sort(waste.begin(), waste.end());
    
    while(t--) {
        cin >> x >> y;
        int cell = (x-1) * m + y;
        int wCount = 0, last = -1;
        for(int i = 0; i < waste.size() && waste[i] <= cell; i++) {
            wCount++;
            last = waste[i];
        }
        int crops = cell - wCount;        
        if(last == cell) cout << "Waste\n";
        else if(crops % 3 == 1) cout << "Carrots\n";
        else if(crops % 3 == 2) cout << "Kiwis\n";
        else if(crops % 3 == 0) cout << "Grapes\n";
    }
}