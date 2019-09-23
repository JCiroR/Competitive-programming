#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;
const int INF = 1 << 30;
const int MAXN = 20010;
vector<pair<int,int> > graph[MAXN];
int d[MAXN];
int p[MAXN];

void dijkstra(int s, int t) {
    priority_queue <pair<int,int>, vector<pair<int,int> > , greater<pair<int, int> > > q;
    q.push(pair<int,int>(0, s));
    while(!q.empty()) {
        int currd = q.top().first;
        int currn = q.top().second;
        q.pop();
        if (currd > d[currn]) continue;
        for(int i = 0; i < graph[currn].size(); i++) {
            int nextN  = graph[currn][i].first;
            int nextW  = graph[currn][i].second;
            if(d[nextN] > currd + nextW) {
                d[nextN] = currd + nextW;
                p[nextN] = currn;
                q.push(pair<int,int>(d[nextN], nextN));
            }
        }
    }
}

int main(void) {
    int ntest, n, m, s, t, from, to, weight, caso = 0;
    cin >> ntest;
    while(ntest--) {
        cin >> n >> m >> s >> t;
        for(int i = 0; i < n + 2; i++) {
            graph[i].clear();
            d[i] = INF;
            p[i] = -1;
        }
        while(m--) {
            cin >> from >> to >> weight;
            graph[from].push_back(pair<int,int>(to,weight));
            graph[to].push_back(pair<int,int>(from,weight));
        }
        d[s] = 0;
        dijkstra(s,t);
        if(d[t] < INF) cout << "Case #" << ++caso << ": " << d[t] << "\n";
        else cout << "Case #" << ++caso << ": unreachable" << "\n";
    }

    return 0;
}