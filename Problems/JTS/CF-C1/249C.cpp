#include <utility>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;
typedef pair<int,int> point;

const int MAXN = 1010, INF = 10000;
char ans[2*MAXN][2*MAXN];
int a[MAXN], n, maxX = -INF, maxY = -INF, minX = +INF, minY = +INF;

void printAns() {
    for(int i = maxY; i >= minY; i--) {
        for(int j = minX; j <= maxX; j++) {
            printf("%c", ans[j][i]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d" , &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<point> c;
    memset(ans, ' ', sizeof(ans));
    int x = 0, y = 0, sign = 1;
    for(int i = 0; i <= n; i++) {
        c.pb(point(x, y));
        x += a[i], y += sign * a[i];
        sign = -sign;
    }
    for(int i = 0; i < c.size() - 1; i++) {
        point from = c[i], to = c[i+1];
        int dx = 1, dy;
        char path;
        if(from.second < to.second) {
            path = '/';
            dy = 1;
        } else {
            path = '\\';
            dy = -1;            
        }
        while(from != to) {
            int coordX = min(from.first, from.first + dx), coordY = min(from.second, from.second + dy);
            ans[1000 + coordX][1000 + coordY] = path;
            maxX = max(maxX, coordX + 1000), maxY = max(maxY, coordY + 1000);
            minX = min(minX, coordX + 1000), minY = min(minY, coordY + 1000);
            from.first += dx;
            from.second += dy;
        }
    }
    printAns();
}
