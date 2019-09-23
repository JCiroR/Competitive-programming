#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 110, INF = 1000000;

int g[MAXN][MAXN], n;

int main() {
    memset(g, 0, sizeof(g));
    int m, from, to, weight;
    cin >> n >> m;
    while(m--) {
        cin >> from >> to >> weight;
        g[from-1][to-1] += weight;
    }
    for(int t = 0; t < n; t++) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(g[i][j] && g[j][k]) {
                    int delta = min(g[i][j], g[j][k]);
                    g[j][k] -= delta;
                    g[i][j] -= delta;
                    g[i][k] += delta;
                }
    }                                     
    int sum = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            sum += g[i][j];
    cout << sum << endl;
}   