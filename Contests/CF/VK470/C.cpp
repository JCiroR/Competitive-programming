#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100000;
long long n, T[MAXN], V[MAXN], aT[MAXN], res[MAXN], num[MAXN], ans[MAXN];
bool mac[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> V[i];
    for(int i = 0; i < n; i++) {
        cin >> T[i];
        aT[i] = T[i];
        if(i > 0) aT[i] += aT[i-1];
    }
    memset(num, 0, sizeof(num));
    memset(mac, false, sizeof(mac));
    for(int i = 0; i < n; i++) {
        if(V[i] == 0) continue;
        long long targ = V[i];
        if(i > 0) targ += aT[i-1];
        auto it = lower_bound(&aT[0], &aT[0] + n, targ);
        int index = int(it - &aT[0]);           
        if(index > 0 && index > i) {
            num[index - 1] += 1;
            mac[i] = true;
        }
        if(index < n && index >= i) res[index] += targ - aT[index - 1];    
    }
    
    long long curr = 0;
    for(int i = n - 1; i >= 0; i--) {        
        curr += num[i];        
        ans[i] = T[i] * curr + res[i];
        if(mac[i]) curr--;
    }
    cout << ans[0];
    for(int i = 1; i < n; i++)
        cout << " " << ans[i];
    cout << endl;
}