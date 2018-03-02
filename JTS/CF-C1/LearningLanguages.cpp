#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> l[105];
vector<int> g[105];
bool seen[105];

void dfs(int u) {
    seen[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        if(!seen[g[u][i]]) dfs(g[u][i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int k, to;
    for(int i = 0; i < n; i++) {
        cin >> k;
        while(k--) {
            cin >> to;
            for(int j = 0; j < l[to].size(); j++) {
                g[i].push_back(l[to][j]);
                g[l[to][j]].push_back(i);
            }
            l[to].push_back(i);
        }
    }
    memset(seen, false, sizeof(seen));
    int count = 0;
    for(int i = 0; i < n; i++)
        if(!seen[i]) {
            count++;
            dfs(i);
        }
    if(count == n) cout << n << endl;
    else cout << count - 1 << endl;
}