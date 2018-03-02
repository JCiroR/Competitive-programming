#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<pair<int,int>, int> cell;

bool seen[8][8];
int dx[8] = {-1, 1, 2 ,2, 1, -1 ,-2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

bool inRange(pair<int,int> p) {
    return (p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8);
}

int dis(int x1, int y1, int x2, int y2) {
    queue<cell> q;
    q.push(make_pair(make_pair(x1, y1), 0));
    while(!q.empty()) {
        cell next = q.front();
        q.pop();
        pair<int,int> coord = next.first;
        seen[coord.first][coord.second] = true;
        if(coord.first == x2 && coord.second == y2) return next.second;

        for(int k = 0; k < 8; k++) {
            pair<int,int> opt = make_pair(coord.first + dx[k], coord.second + dy[k]);
            if(inRange(opt) && !seen[opt.first][opt.second])
                q.push(make_pair(opt, next.second + 1));
        }
    }
    return -1;
}

int main() {
    char c1, c2;
    int n1, n2;
    while(scanf("%c%d %c%d\n", &c1, &n1, &c2, &n2) == 4) {
        memset(seen, false, sizeof(seen));
        int x1 = n1 - 1, y1 = c1 - 'a';
        int x2 = n2 - 1, y2 = c2 - 'a';
        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1, n1, c2, n2, dis(x1, y1, x2, y2));
    }
}