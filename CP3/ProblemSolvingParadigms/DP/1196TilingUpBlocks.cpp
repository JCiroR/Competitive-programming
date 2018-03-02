#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 11000;
int L[MAXN];

int main(void) {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        vector<pair<int,int> > b; 
        b.reserve(n);
        
        int l, m;
        while(n--) {
            cin >> l >> m;
            b.push_back(make_pair(l,m)); 
        }
        sort(b.begin(), b.end());

       for(int i = 0; i < n; i++) L[i] = 500;

        int lis = 0;
        for(int i = 0; i < b.size(); i++) {
            int pos = upper_bound(L, L + lis, b[i].second) - L;
            L[pos] = b[i].second;
            if(pos + 1 > lis) lis++; 
        }

        cout << lis << endl;
    }
    cout <<  '*' << endl;
}