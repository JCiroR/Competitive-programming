#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int t[1010];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    memset(t, 0, sizeof(t));
    while(m--) {
        int temp; cin >> temp;
        t[temp - 1]++;
    }
    int ans = 0;
    
    bool pos = true;
    while(pos) {
        for(int i = 0; i < n; i++) {
            if(t[i] == 0) {
                pos = false;
                break;
            }
            t[i]--;
        }
        if(pos) ans++;
    }
    cout << ans << endl;

}