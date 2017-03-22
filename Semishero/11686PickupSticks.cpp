#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
vector<int> graph[MAXN];
bool imIn[MAXN];
bool visited[MAXN];
vector<int> topoSort;
bool posible = true;

void dfs(int node) {
    visited[node] = true;
    imIn[node] = true;
    for(int i = 0; i < graph[node].size(); i++) {
        int v = graph[node][i];
        if(imIn[v]) {
            posible = false;
            break;
        } else if(!visited[v]) dfs(v);
    }
    topoSort.push_back(node);
    imIn[node] = false;
}

void clearUntil(int n) {
     for(int i = 0; i < n; i++) {
        visited[i] = false;
        imIn[i] = false;
        graph[i].clear();
    }
}

int main(void) {
    int n, m, a, b;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        topoSort.clear();
        posible = true;
        clearUntil(n);
        while(m--) {
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
        }
        for(int i = 0; i < n && posible; i++) if(!visited[i]) dfs(i);
        if(!posible) cout << "IMPOSSIBLE\n";
        else {
          reverse(topoSort.begin(), topoSort.end());
          for(vector<int>::iterator it = topoSort.begin(); it != topoSort.end(); ++it) cout << (*it + 1) << "\n";
        }
    }
    return 0;
}