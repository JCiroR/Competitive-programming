#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int MAXN = 1e5;

int coin[110], n;
bool sum[MAXN];

void knap() {
    for(int k = 0; k < n; k++)
    for(int j = MAXN - 1; j >= 0; j--) {
        if(sum[j] && j + coin[k] < MAXN) 
            sum[j + coin[k]] = true;
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int total = 0;
        for(int i = 0; i < n; i++)  {
            cin >> coin[i];
            total += coin[i];
        }
        memset(sum, false, sizeof(sum));
        sum[0] = true;
        knap();
        int ans = 10000000;
        for(int i = 0; i < MAXN; i++) {
            if(sum[i]) ans = min(ans, abs( (total - i) - i));
        }
        cout << ans << endl;
    }
}