#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>

using namespace std;

const int MAXV = 55;

vector<pair<int,int> > AdjList[MAXV];
int deg[MAXV];
bool seen[MAXV];
list<int> cyc;

void dfs(int u) {
    seen[u] = true;
    for(int i = 0; i < AdjList[u].size(); i++) {
        if(!seen[AdjList[u][i].first]) dfs(AdjList[u][i].first);
    }
}

bool Connected() {
    int runs = 0;
    for(int i = 1; i <= 50; i++) {
        if(deg[i] > 0 && !seen[i]) {
            dfs(i);
            runs++;
        }
    }
    return runs == 1;
}

bool Eulerian() {
    for(int i = 1; i <= 50; i++)
        if(deg[i] % 2 != 0) return false;
    return true;
}

void EulerTour(list<int>::iterator it, int u) {
    for(int j = 0; j < (int)AdjList[u].size(); j++) {
        pair<int,int> v = AdjList[u][j];
        if(v.second) {
            AdjList[u][j].second = 0;
            v.second = 0;
            for(int k = 0; k < (int)AdjList[v.first].size(); k++) {
                pair<int,int> uu = AdjList[v.first][k];
                if(uu.first == u && uu.second) {
                    AdjList[v.first][k].second = 0;
                    uu.second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(it, u), v.first);
        }
    }
}


int main(void) {
    int cT = 1, T;
    cin >> T;
    while(T--) {
        memset(deg, 0, sizeof(deg));
        for(int i = 0; i < MAXV; i++) AdjList[i].clear();
        int N;
        int A, B;
        cin >> N;
        while(N--) {
            cin >> A >> B;
            AdjList[A].push_back(make_pair(B, 1));
            AdjList[B].push_back(make_pair(A, 1));
            deg[A]++; 
            deg[B]++;
        }
        
        memset(seen, false, sizeof(seen));
        bool connected = Connected(),  eulerian = Eulerian();
        
        printf("Case #%d\n", cT++);
        if(connected && eulerian) {
            cyc.clear();
            for(int i = 1; i <= 50; i++) {
                if(deg[i] > 0) {
                    EulerTour(cyc.begin(), i);
                    break;
                }
            }
            int last = -1, first = -1;
            for(list<int>::iterator it = cyc.begin(); it != cyc.end(); it++) {
                if(last != -1) {
                    printf("%d %d\n", last, *it);
                } else first = *it;
                last = *it;
            }
            printf("%d %d\n", last, first);
        } else printf("some beads may be lost\n");
        if(T) printf("\n");
    }
    return 0;
}