#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 110;

int laces[MAXN], g[MAXN][MAXN], n, m;

int main() {
    memset(g, 0, sizeof(g));
    memset(laces, 0, sizeof(laces));
    cin >> n >> m;
    int from, to;
    while(m--) {
        cin >> from >> to;
        g[from-1][to-1] = 1;
        g[to-1][from-1] = 1;
    }

    int ans = 0;
    bool change = true;
    while(change) {
        change = false;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = 0; j < n; j++)
                if(g[i][j] == 1) temp++;
            laces[i] = temp;
        }
        for(int i = 0; i < n; i++) {
            if(laces[i] == 1) {
                change = true;
                laces[i]--;
                for(int j = 0; j < n; j++)
                    if(g[i][j] == 1) {
                        g[i][j] = g[j][i] = 0;
                        break;
                    }
            }
        }
        if(change) ans++;
    }
    cout << ans << endl;
}