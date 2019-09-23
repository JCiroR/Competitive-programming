#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

const int MAXN = 10000;
vector<int> g[MAXN]; int low[MAXN], num[MAXN], parent[MAXN]; bool visited[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > links;

int iteration = 0;

void find_bridges(int u) {
    num[u] = low[u] = iteration++;
    visited[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(child == u) continue;
        if(!visited[child]) {
            parent[child] = u;
            find_bridges(child);
            low[u] = min(low[u], low[child]);
            if(low[child] > num[u]) {
                pair<int,int> p = make_pair(min(child, u),max(child, u));
                links.push(p);
            }
        } else if(parent[u] != child) low[u] = min(low[u], low[child]);
    }
}

void clear(int n) {
    for(int i = 0; i <= n; i++) g[i].clear();
    memset(low, -1, sizeof(low));
    memset(num, -1, sizeof(num));
    memset(parent, -1, sizeof(parent));
    memset(visited, false, sizeof(visited));
}

int main(void) {
    int n;
    while(scanf("%d", &n) == 1) {
        if(n == 0) {
            printf("0 critical links\n\n");
            continue;
        }
        links = priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >();
        clear(n);

        int from, to, edges;
        for(int i = 0; i < n; i++) {
            scanf("%d (%d) ", &from, &edges);
            while(edges--) {
                scanf("%d", &to);
                g[from].push_back(to);
                g[to].push_back(from);
            }
        }
        for(int i = 0; i < n; i++) {
            iteration = 0;
            if(!visited[i]) find_bridges(i);            
        }
        
        printf("%d critical links\n", (int)links.size());
        while(!links.empty()){
            pair<int,int> p = links.top();
            links.pop();
            printf("%d - %d\n", p.first, p.second);
        }
        printf("\n");
    }
    return 0;
}