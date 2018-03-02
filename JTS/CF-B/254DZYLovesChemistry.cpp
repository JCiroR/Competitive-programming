#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans = 1;

vector<int> g[51];
bool seen[51];

void dfs(int u) {
    seen[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int c = g[u][i];
        if(!seen[c]) {
            ans *= 2;
            dfs(c);
        }
    }
}

int main() {
    fill(g, g + 51, vector<int>());
    memset(seen, false, sizeof(seen));
    int n, m;
    cin >> n >> m;
    int q1, q2;
    while(m--) {
        cin >> q1 >> q2;
        q1--; q2--;
        g[q1].push_back(q2);
        g[q2].push_back(q1);
    }
    for(int i = 0; i < n; i++) if(!seen[i]) dfs(i);    
    cout << ans << endl;
}