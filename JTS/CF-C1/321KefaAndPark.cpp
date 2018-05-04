#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 100010;
int n, m, ans = 0;
vector<int> g[MAXN];
bool cat[MAXN],seen[MAXN];


void dfs(int u, int cons) {
    seen[u] = true;
    cons += (cat[u]? 1: 0);
    if(cons > m) return;
    bool leaf = true;
    for(int i = 0; i < g[u].size(); i++) {
        int c = g[u][i];
        if(!seen[c]) {            
            leaf = false;
            if(cat[u]) dfs(c, cons);
            else dfs(c, 0);
        }
    }
    if(leaf) ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) g[i].clear();        
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp == 1) cat[i] = true;
        else cat[i] = false;
    }
    int from, to;
    for(int i = 0; i < n-1; i++) {
        cin >> from >> to;
        g[from-1].push_back(to-1);
        g[to-1].push_back(from-1);
    }    
    memset(seen, false, sizeof(seen));    
    dfs(0, 0);        
    cout << ans << endl;
}