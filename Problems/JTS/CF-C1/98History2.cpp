#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int ai, bi;  
    vector<pair<int, int> > ev;
    for(int i = 0; i < n; i++) {
        cin >> ai >> bi;        
        ev.push_back(make_pair(ai, bi));
    }
    sort(ev.begin(), ev.end());
    int ans = 0, max_b = -1;
    for(int i = 0; i < ev.size(); i++) {
       pair<int,int> c = ev[i];
       if(c.second > max_b) max_b = c.second;
       else if(c.second < max_b) ans++;
    }
    cout << ans << endl;
}