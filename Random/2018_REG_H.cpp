#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef tuple<ll, ll, int> arc;

const int N = 1e4 + 10;
const ll INF = 1e17;
vector<edge> g[N];
int n, m;

pair<int, int> p[N];
ll dist[N], mant[N];

void dijkstra(int s) {
    fill(&dist[0], &dist[0] + n, INF);
    fill(&mant[0], &mant[0] + n, INF);
    dist[s] = mant[s] = 0;
    p[s] = mp(s, 0);
    priority_queue<arc, vector<arc>, greater<arc> > pq; pq.push(arc(0, 0, s));
    while(!pq.empty()) {
        arc front = pq.top(); pq.pop();
        ll d = get<0>(front), m = get<1>(front), u = get<2>(front);
        if(d > dist[u]) continue;
        if(d == dist[u] && m > mant[u]) continue;

        for(int j = 0; j < g[u].size(); j++) {
            edge v = g[u][j];
            int nextV = get<0>(v);
            ll nextDist = dist[u] + get<1>(v);
            ll nextMant = get<2>(v);

            if(nextDist < dist[nextV] || (nextDist == dist[nextV] && nextMant < mant[nextV])) {
                dist[nextV] = nextDist;
                mant[nextV] = nextMant;
                p[nextV] = mp(u, j);
                pq.push(arc(nextDist, nextMant, nextV));
            } 
        }
    }
}

ll dfs(int u) {
    ll ans = 0;
    for(int i = 0; i < g[u].size(); i++) {
        edge e = g[u][i];
        int nextV = get<0>(e);
        if(p[nextV].ff == u && p[nextV].ss == i) {
            ans += get<2>(e);
            ans += dfs(nextV);
        }
    }
    return ans;
}

int main () {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int from, to, dis, man;
        scanf("%d %d %d %d", &from, &to, &dis, &man);
        from--, to--;
        g[from].pb(edge(to, dis, man));
        g[to].pb(edge(from, dis, man));
    }
    dijkstra(0);
    ll ans = dfs(0);
    printf("%lld\n", ans);
}