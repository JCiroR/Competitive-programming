#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

long long a[60], b[60], best[60];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];    
    for(int i = 0; i < n; i++) {
        long long worst  = -1000000000LL * 1000000000LL;
        for(int j = 0; j < m; j++) worst = max(worst, a[i] * b[j]);
        best[i] = worst;
    }
    sort(best, best + n, greater<long long>());
    cout << best[1] << endl;    
}