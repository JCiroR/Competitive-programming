#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, p;
bool g[24][24];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> p;
        memset(g, false, sizeof(g));
        for(int i = 0; i < n; i++) {
            int need = 2;
            for(int j = 0; j < n; j++) {
                if(!(need || p)) break;
                if(!g[i][j] && i != j) {
                    g[i][j] = g[j][i] = true;
                    if(need) need--;
                    else if(p) p--;
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(g[i][j]) {
                    g[i][j] = g[j][i] = false;
                    cout << i+1 << " " << j+1 << endl;
                }
            }
    }
}