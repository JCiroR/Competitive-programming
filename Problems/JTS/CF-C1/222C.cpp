#include <bits/stdc++.h>
using namespace std;

char mat[510][510];
bool vis[510][510];
int n, m, k;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == '.';
}

void solve(int r, int c) {
    vis[r][c] = true;
    for(int d = 0; d < 4; d++) {
        int nextR = r + dr[d], nextC = c + dc[d];
        if(inRange(nextR, nextC) && !vis[nextR][nextC]) 
            solve(nextR, nextC);
    }
    if(k > 0) {
        k--;
        mat[r][c] = 'X';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(vis, false, sizeof(vis));
    cin >> n >> m >> k;
    int xSt, ySt;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == '.') xSt = i, ySt = j;
        }
    if(k != 0) solve(xSt, ySt);
    for(int i = 0; i < n; i++)
        cout << &mat[i][0] << endl;
}