#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 5010;

bool best[MAXN], worst[MAXN], seen[MAXN];
vector<int> g[MAXN];
vector<int> p;
int N;

int dfs1(int u, int depth) {
    seen[u] = true;
    int max_d = depth;
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(!seen[child]) 
            max_d = max(max_d, dfs1(child, depth + 1));
    }
    return max_d;
}

void dfs2(int u, int depth, int max_depth) {
    seen[u] = true;
    p.push_back(u); 
    if(depth == max_depth) {
        worst[u] = true;
        best[p[depth/2]] = true;
        if(depth % 2 != 0) 
            best[p[depth/2 + 1]] = true;
    }
    for(int i = 0; i < g[u].size(); i++) {
        if(!seen[g[u][i]])
            dfs2(g[u][i], depth + 1, max_depth);
    }
    p.pop_back();
}

int bfs() {
    queue<int> q; 
    q.push(0);
    seen[0] = true;
    int last;
    while(!q.empty()) {
        last = q.front();
        q.pop();
        for(int i = 0; i < g[last].size(); i++) {
            int child = g[last][i];
            if(!seen[child]) {
                seen[child] = true;
                q.push(child);
            }
        }   
    }
    return last;
}

int main(void) {
    while(scanf("%d", &N)==1) {
        for(int i = 0; i <= N; i++) g[i].clear();
        for(int i = 0; i < N; i++) {
            int K, to;
            scanf("%d", &K);
            while(K--) {
                scanf("%d", &to);
                to--;
                g[i].push_back(to);
            }
        }
        memset(seen, false, sizeof(seen));
        int last = bfs();
        memset(seen, false, sizeof(seen));
        int depth = dfs1(last, 0);
        memset(best, false, sizeof(best));
        memset(worst, false, sizeof(worst));
        memset(seen, false, sizeof(seen));
        worst[last] = true;
        p.clear();
        p.reserve(MAXN);
        dfs2(last, 0, depth);
        memset(seen, false, sizeof(seen));
        for(int i = 0; i < N; i++) {
            if(worst[i] && i != last) {
                dfs2(i, 0, depth);
                break;
            }
        }
        printf("Best Roots  :");
        for(int i = 0; i < N; i++) 
            if(best[i]) printf(" %d", i + 1);
        printf("\nWorst Roots :");
         for(int i = 0; i < N; i++) 
            if(worst[i]) printf(" %d", i + 1);
        printf("\n"); 
     }
    return 0;
}