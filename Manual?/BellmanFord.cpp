#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int INF = 10000;
const int MAXV = 1000;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dist[MAXV];
vector<vii> AdjList;

//Updates dist, returns whether the graph has a negative cycle
bool bellmanFord(int s, int V) {
    memset(dist, INF, sizeof(dist)); dist[s] = 0;
    //Relax every edge at most v-1 times
    bool updated = true;
    for (int i = 0; i < V - 1 && updated; i++) {
        updated = false;
        for(int u = 0; u < V; u++)
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if(dist[v.first] > dist[u] + v.second) {
                    updated = true; //Something changed on this iteration
                    dist[v.first] = dist[u] + v.second;
                }            
            }
    }
    //Check negative cycle: One more pass
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++)
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            //If the shortest path can still be updated
            if (dist[v.first] > dist[u] + v.second) hasNegativeCycle = true;    
        }
    return hasNegativeCycle;
}

int main(void) {
    int V, E; cin >> V >> E;
    AdjList.assign(V, vii());
    int from, to, weight;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        AdjList[from].push_back(ii(to, weight));
    }
}