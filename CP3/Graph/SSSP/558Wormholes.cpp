#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int INF = 1000000000;
const int MAXV = 1010;

typedef pair<int,int> ii;.
typedef vector<int> vi;
typedef vector<ii> vii;

int dist[MAXV];
vector<vii> AdjList;

bool bellmanFord(int s, int V) {
    memset(dist, INF, sizeof(dist)); dist[s] = 0;
    bool updated = true;

    for(int i = 0; i < V - 1 && updated; i++) {
        updated = false;
        for(int u = 0; u < V; u++)
            for(int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if(dist[v.first] > dist[u] + v.second) {
                    updated = true;
                    dist[v.first] = dist[u] + v.second;
                }
            }
    }

    bool hasNegativeCycle = false;
    for(int u = 0; u < V; u++)
        for(int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if(dist[v.first] > dist[u] + v.second) hasNegativeCycle = true;
        }
    return hasNegativeCycle;
}

int main(void) {
    int c; scanf("%d", &c);
    while(c--) {
        int n, m;
        scanf("%d %d", &n, &m);
        AdjList.assign(n, vii());
        int from, to, years;
        while(m--) {
            scanf("%d %d %d", &from, &to, &years);
            AdjList[from].push_back(ii(to, years));
        }
        if(bellmanFord(0, n)) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}