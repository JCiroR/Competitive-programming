#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 101, INF = 10000 * 1000;
const int B = (1 << 13) - 1;

int graph[N][N];
int dp[B][N];
ii req[12];
int n, m, b, req_s;

int fun(int mask, int p) {
    if(mask == 0) {
        return dp[mask][p] = graph[p][b];
    }
    int & val = dp[mask][p];
    if(val != -1) return val;
    val = INF;
    for(int i = 0; i < req_s; i++) {
        if(mask & (1 << i)) {
            ii r = req[i];
            int dis = graph[p][r.ff] + graph[r.ff][r.ss];
            dis += fun((mask ^ (1 << i)) , r.ss);
            val = min(val, dis);
        }
    }
    return val;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &b);
        b--;
        fill_n(&graph[0][0], N*N, INF);
        for(int i = 0; i < m; i++) {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            u--, v--;
            graph[u][v] = graph[v][u] = d;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++) 
                for(int j = 0; j < n; j++) {
                    if(i == j) graph[i][i] = 0;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);    
                }
        int z;
        req_s = 0;
        scanf("%d", &z);
        for(int i = 0; i < z; i++) {
            int u, v, b_j;
            scanf("%d %d %d", &u, &v, &b_j);
            u--, v--;
            while(b_j--)
                req[req_s++] = ii(u, v);
        }
        memset(dp, -1, sizeof(dp));
        fun((1 << req_s) - 1, b);
        cout << dp[(1 << req_s) - 1][b] << endl;
    }
}