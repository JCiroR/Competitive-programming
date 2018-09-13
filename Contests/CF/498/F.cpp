#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20;

map<long long, int> v[N][N];
ll a[N][N], k, ans = 0;
int n, m, mid;

void solveTL(int x, int y, ll xorS, int cnt) {
    xorS ^= a[x][y];
    if(cnt == mid) {
        v[x][y][xorS]++;
        return;
    }
    if(x + 1 < n) solveTL(x + 1, y, xorS, cnt + 1);
    if(y + 1 < m) solveTL(x, y + 1, xorS, cnt + 1);
}

void solveBR(int x, int y, ll xorS, int cnt) {
    if(cnt == (n + m - 2) - mid) {
        if(v[x][y].count(xorS ^ k))
            ans += v[x][y][xorS ^ k];
        return;
    }
    xorS ^= a[x][y];
    if(x > 0) solveBR(x - 1, y, xorS, cnt + 1);
    if(y > 0) solveBR(x, y - 1, xorS, cnt + 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
    }

    mid = (m + n - 2)/2;
    solveTL(0, 0, 0, 0);
    solveBR(n - 1, m - 1, 0, 0);
    cout << ans << endl;
}