#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
int m, n, k;
pair<int, int> row[MAXN], col[MAXN];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    fill_n(col, MAXN, make_pair(-1, 0));
    fill_n(row, MAXN, make_pair(-1, 0));
    int op, tar, color;
    for(int i = 1; i <= k; i++) {
        scanf("%d %d %d", &op, &tar, &color);
        if(op == 1) row[tar] = make_pair(i, color);
        else col[tar] = make_pair(i, color);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pair<int,int> p = max(row[i], col[j]);
            if(j > 1) printf(" ");
            printf("%d", p.second);
        }
        printf("\n");
    }
}