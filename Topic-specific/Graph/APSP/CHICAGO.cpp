//https://www.spoj.com/problems/CHICAGO/
#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int n, m;
double graph[N][N];
double INF = -1;

int main() {
    while(scanf("%d %d", &n, &m) == 2) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                graph[i][j] = INF;
        int a, b;
        double p;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %lf", &a, &b, &p);
            a--, b--;
            p /= 100.0;
            graph[a][b] = graph[b][a] = p;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    if(graph[i][k] == INF || graph[k][j] == INF) continue;
                    graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);
                }
        double ans = graph[0][n-1] * 100;
        printf("%.6lf percent\n", ans);
    }
}