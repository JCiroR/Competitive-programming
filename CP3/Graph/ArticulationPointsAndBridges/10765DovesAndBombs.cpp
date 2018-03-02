#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 10005;
vector<int> g[MAXN]; int low[MAXN], num[MAXN], parent[MAXN], AP[MAXN]; bool visited[MAXN];
int iteration = 0;
int rootChildren = 0;

void clear(int n) {
    for(int i = 0; i < n; i++) g[i].clear();
    memset(low, -1, sizeof(low));
    memset(num, -1, sizeof(num));
    memset(parent, -1, sizeof(parent));
    memset(AP, 0, sizeof(AP));
    memset(visited, false, sizeof(visited));
}

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b) {
        if(b.second == a.second) return b.first < a.first;
        else if(b.second > a.second) return true;
        else return false;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int> >  , Compare> options;

void findAP(int u) {
    int children = 0; 
    num[u] = low[u] = iteration++;
    visited[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(!visited[child]) {
          if(u == 0) rootChildren++;
            children++;
            parent[child] = u;
            findAP(child);
            low[u] = min(low[u], low[child]);
            if(parent[u] == -1 && children > 1) AP[u]++;
            else if(parent[u] != -1 && low[child] >= num[u]) AP[u]++;
        } else if(parent[u] != child) low[u] = min(low[u], num[child]);
    }
}

int main(void) {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 && (n || m)) {
        clear(n);
        options = priority_queue<pair<int,int>, vector<pair<int,int> >  ,  Compare>();
        int from, to;
        while(scanf("%d %d", &from, &to) == 2 && (from != -1 || to != -1)) {
            g[from].push_back(to);
            g[to].push_back(from);
        }
        iteration = 0;
        rootChildren = 0 ;
        findAP(0);
        if(rootChildren > 1) AP[0]++;

        for(int i = 0; i < n; i++) {
            if(AP[i] != 0) {
                pair<int,int> p = make_pair(i, AP[i]);
                if(parent[i] != -1) p.second = p.second + 1;
                options.push(p);
            }
        }

        int cont = 0;
        while(cont < m && !options.empty()) {
            pair<int,int> p = options.top();
            options.pop();
            printf("%d %d\n", p.first, p.second);
            cont++;
        }
        for(int i = 0; i < n && cont < m; i++) {
            if(AP[i] == 0) {
                printf("%d %d\n", i, 1);
                cont++;
            }
        }
        printf("\n");
    }
    return 0;
}