#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100005;

vector<int> g[MAXN];stack<int> S; vector<bool> sccs; 
int low[MAXN], num[MAXN], belong_to[MAXN]; bool visited[MAXN];

int discTime = 0;

void clear(int n) {
    for(int i = 0; i < n; i++) g[i].clear();
    S = stack<int>();
    sccs.clear();
    memset(visited, false, sizeof(visited));
    memset(belong_to, -1, sizeof(belong_to));
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(low));
}

void tarjanSCC(int u) {
    low[u] = num[u] = discTime++;
    S.push(u); visited[u] = true;
    
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(num[child] == -1) tarjanSCC(child);
        if(visited[child]) low[u] = min(low[child], low[u]);
    }

    if(low[u] == num[u]) {
        int index = sccs.size();
        sccs.push_back(false);
        while(true) {
            int v = S.top(); S.pop(); visited[v] = false;
            belong_to[v] = index; 
            if(v == u) break;
        }
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        clear(n);
        int from, to;
        while(m--) {
            scanf("%d %d", &from, &to);
            from--; to--;
            g[from].push_back(to);
        }
        if(n == 0) {
            printf("0\n");
            continue;
        }
        discTime = 0;
        for(int i = 0; i < n; i++)
            if(num[i] == -1) tarjanSCC(i);
        
        for(int i = 0; i < n; i++) for(int j = 0; j < g[i].size();j++) {
            int v = g[i][j];
            if(belong_to[i] != belong_to[v]) sccs[belong_to[v]] = true;
        }

        int kdn = 0;
        for(int i = 0; i < sccs.size(); i++) if(!sccs[i]) kdn++;
        printf("%d\n", kdn);
    }
    return 0;
}