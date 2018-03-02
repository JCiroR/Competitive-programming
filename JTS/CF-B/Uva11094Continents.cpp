#include <cstring>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

const int MAXN = 30;

char g[MAXN][MAXN], land = 'l';
bool seen[MAXN][MAXN];
int n, m, x, y;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

bool inRange(ii p) {
    return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}

int bfs(int r, int c) {
    queue<ii> q;
    q.push(make_pair(r,c));
    seen[r][c] = true;
    int ans = 1;
    while(!q.empty()) {
        ii curr = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            ii opt = make_pair(curr.first + dr[d], curr.second + dc[d]);
            if(opt.second == m) opt.second = 0;
            else if(opt.second == -1) opt.second = m - 1;
            if(inRange(opt) && !seen[opt.first][opt.second] && g[opt.first][opt.second] == land) {
                ans++;
                seen[opt.first][opt.second] = true;
                q.push(opt);
            }
        }
    }
    return ans;
}

int main() {
    while(cin >> n >> m) { 
        memset(seen, false, sizeof(seen));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];
        cin >> x >> y;
        land = g[x][y];
        bfs(x, y);
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == land && !seen[i][j]) ans = max(ans, bfs(i, j));
        cout << ans << endl;
    }
}