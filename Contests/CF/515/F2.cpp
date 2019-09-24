#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 10;

ll dp[N][2];
ii gpoints[N][2];
ii points[N];
int n, g;

bool cmp(ii a, ii b) {
    int gA = max(a.first, a.second);
    int gB = max(b.first, b.second);
    int sgA = min(a.first, a.second);
    int sgB = min(b.first, b.second);

    if(gA < gB) return true;
    if(gA == gB && sgA < sgB) return true;
    return false;
}

ll dist(ii a, ii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void fun() {
    dp[g-1][0] = dp[g-1][1] = 0;
    for(int i = g - 2; i >= 0; i--) {
        ii x1 = gpoints[i][0];
        ii y1 = gpoints[i][1];
        ii x2 = gpoints[i+1][0];
        ii y2 = gpoints[i+1][1];
        // printf("%d: %d,%d|%d,%d\n", i, x1.first, x1.second, y1.first, y1.second);
        // printf("%d: %d,%d|%d,%d\n", i + 1, x2.first, x2.second, y2.first, y2.second);

        dp[i][0] = dist(x1, x2) + dist(x2, y2) + dp[i+1][1];
        dp[i][0] = min(dp[i][0], dist(x1, y2) + dist(y2, x2) + dp[i+1][0]);

        dp[i][1] = dist(y1, y2) + dist(y2, x2) + dp[i+1][0];
        dp[i][1] = min(dp[i][1], dist(y1, x2) + dist(x2, y2) + dp[i+1][1]);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[i] = ii(x, y);
    }
    sort(points, points + n, cmp);
    gpoints[0][0] = gpoints[0][1] = ii(0, 0);
    g = 0;
    int llev = 0;
    bool xAxis = true, yAxis = true;
    ii lastAdded;
    for(int i = 0; i < n; i++) {
        ii p = points[i];
        int clev = max(points[i].first, points[i].second);
        int cslev = min(points[i].first, points[i].second);
        if(llev != clev) {
            if(!xAxis) gpoints[g][0] = lastAdded;
            if(!yAxis) gpoints[g][1] = lastAdded;
            g++;
            xAxis = yAxis = false;
            llev = clev;
        }
        if(!xAxis && p.first == cslev) {
            gpoints[g][0] = p;
            xAxis = true;
        }
        if(!yAxis && p.second == cslev) {
            gpoints[g][1] = p;
            yAxis = true;
        }
        lastAdded = p;
    }
    if(!xAxis) gpoints[g][0] = lastAdded;
    if(!yAxis) gpoints[g][1] = lastAdded;
    if(n > 0) g++;
    fun();
    cout << min(dp[0][0] , dp[0][1]) << endl;
}