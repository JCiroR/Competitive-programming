#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> s;
        int r = 0, k = 0, delta = 0, bestDelta = -100000000;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'K') {
                delta++;
                k++;
            }  else {
                delta--;
                r++;
            }
            bestDelta = max(bestDelta, delta);
            if(delta < 0) delta = 0;
        }
        cout << r + bestDelta << endl;
    }
}  