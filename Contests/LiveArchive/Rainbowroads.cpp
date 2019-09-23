#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 10;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef pair<int,int> edge;

vector<edge> g[N];
vector<edge> pending;
bool good[N];
int n, k;

bool dfs(int u, int from, int col) {
    if(good[u]) k--;
    good[u] = false;
    for(int i = 0; i < g[u].size(); i++) {
        edge curr = g[u][i];
        if(curr.ss == from) continue;
        if(curr.ff == col) return true;
        if(dfs(curr.ss, u, curr.ff)) return true;
    }
    return false;
}

void processNode(int u) {
    pending.clear();
    int prevCol = -1, j = 0, firstNode = -1;
    for(int i = 0; i < g[u].size(); i++) {
        edge curr = g[u][i];
        if(curr.ff == prevCol) {
            if(firstNode != -1) {
                pending.pb(mp(prevCol, firstNode));
                firstNode = -1;
            }
            pending.pb(mp(prevCol, curr.ss));
        } else {
            prevCol = curr.ff;
            firstNode = curr.ss;
        }
    }
    for(edge e: pending)
        if(dfs(e.ss, u, e.ff)) { 
            k = 0;
            return;
        }
}

int main () {
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) { 
            g[i].clear();
            good[i] = true;
        }
        k = n;
        for(int i = 0; i < n - 1; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            g[a].pb(mp(c, b));
            g[b].pb(mp(c, a));
        }
        for(int i = 0; i < n; i++)
            sort(g[i].begin(), g[i].end());
        for(int i = 0; i < n; i++)
            if(good[i]) processNode(i);
        printf("%d\n", k);
        if(k != 0)
            for(int i = 0; i < n; i++) {
                if(good[i]) printf("%d\n", i + 1);
            }
    }   
}