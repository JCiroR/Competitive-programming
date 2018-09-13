#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 20;
int ind[maxn], size[maxn], ans[maxn], n, q, p, curr = 0;
vector<int> g[maxn];
bool seen[maxn];

int dfs(int u) {
    seen[u] = true;
    ans[curr] = u;
    ind[u] = curr++; 
    size[u] = 1;
    for(int i = 0; i < g[u].size(); i++) {
        int c = g[u][i];
        if(!seen[c]) size[u] += dfs(c);
    }
    return size[u];
}

int main(void) {
    scanf("%d%d",&n,&q);
    for(int i = 0; i < maxn; i++) g[i].clear();
    memset(seen, false, sizeof(seen));
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p);
        g[p].push_back(i);
    }
    dfs(1);
    int u, k;
    while(q--) {
        scanf("%d %d", &u, &k);
        if(size[u] < k) { 
            printf("-1\n");
            continue;
        }
        printf("%d\n", ans[ind[u] + (k - 1)]);
    }
}