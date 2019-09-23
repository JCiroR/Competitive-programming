#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef tuple<ll, int , int> edge;
typedef pair<ll, int> li;

const int N = 3e5 + 1;
const ll INF = 1e16;
int n, m, k, ansSize;
vector<edge> g[N];
int p[N];
ll dist[N];
int ans[N];

void dijkstra(int s) {
    fill(&dist[0], &dist[0] + n, INF);
    dist[s] = 0, p[s] = s;
    priority_queue<li, vector<li>, greater<li> > pq; pq.push(li(0LL, s));
    while(!pq.empty()) {
        li front = pq.top(); pq.pop();
        ll d = front.ff, u = front.ss;
        if(d > dist[u]) continue;
        for (int j  = 0; j < g[u].size(); j++) {
            edge v = g[u][j];
            if(dist[u] + get<0>(v) < dist[get<1>(v)]) {
                dist[get<1>(v)] = dist[u] + get<0>(v);
                pq.push(li(dist[get<1>(v)], get<1>(v)));
                p[get<1>(v)] = u;
            }
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int from, to, dis;
        scanf("%d %d %d", &from, &to, &dis);
        from--, to--;
        g[from].pb(edge(dis, to, i));
        g[to].pb(edge(dis, from, i));
    }
    dijkstra(0);
    ansSize = 0;

    queue<int> q;
    q.push(0);
    while(!q.empty() && ansSize < k) {
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            edge e = g[u][i];
            int v = get<1>(e);
            if(p[v] == u) {
                ans[ansSize++] = get<2>(e);            
                q.push(v);
            }
            if(ansSize >= k) break;
        }
    }

    printf("%d\n", ansSize);
    for(int i = 0; i < ansSize; i++) {
        if(i > 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}