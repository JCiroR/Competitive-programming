#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10005;

vector<int> g[MAXN];
int color[MAXN], n;
bool seen[MAXN];

int dfs(int u) {
    seen[u] = true;
    int steps = 0;
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(!seen[child]) {
            steps += dfs(child);
            if(color[u] != color[child]) steps++;
        }
    }
    return steps;
}

int main(void) {
    memset(color, 0, sizeof(color));
    memset(seen, false, sizeof(seen));
    for(int i = 0; i < MAXN; i++) g[i].clear();

    cin >> n;
    int pi, col;
    for(int i = 1; i < n; i++) {
        cin >> pi; pi--;
        g[i].push_back(pi);
        g[pi].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> col;
        color[i] = col;
    }
    cout << dfs(0) + 1 << endl;
    return 0;
}