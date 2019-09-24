#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;

int board[N][N];
int p1[N*N][2];
int p2[N*N][2];

int n, next_p1, next_p2;

inline bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int check_loss(int p) {
    if(p == 1) {
        int x1 = p1[next_p1 - 1][0],    y1 = p1[next_p1 - 1][1];
        for(int i = 0; i < next_p1 - 1; i++) {
            int dx = p1[i][0] - x1,     dy = p1[i][1] - y1;
            int x3 = p1[i][0] - dy,     y3 = p1[i][1] + dx;
            int x4 = x3 - dx,           y4 = y3 - dy;
            if(in_range(x3, y3) && in_range(x4, y4) && board[x3][y3] == p && board[x4][y4] == p)
                return p;
            
            dx = x1 - p1[i][0],         dy = y1 - p1[i][1];
            x3 = x1 - dy,               y3 = y1 + dx;
            x4 = x3 - dx,               y4 = y3 - dy;
            if(in_range(x3, y3) && in_range(x4, y4) && board[x3][y3] == p && board[x4][y4] == p)
                return p;
        }
    } else {
        int x1 = p2[next_p2 - 1][0],    y1 = p2[next_p2 - 1][1];
        for(int i = 0; i < next_p2 - 1; i++) {
            int dx = p2[i][0] - x1,     dy = p2[i][1] - y1;
            int x3 = p2[i][0] - dy,     y3 = p2[i][1] + dx;
            int x4 = x3 - dx,           y4 = y3 - dy;
            if(in_range(x3, y3) && in_range(x4, y4) && board[x3][y3] == p && board[x4][y4] == p)
                return p;

            dx = x1 - p2[i][0],         dy = y1 - p2[i][1];
            x3 = x1 - dy,               y3 = y1 + dx;
            x4 = x3 - dx,               y4 = y3 - dy;
            if(in_range(x3, y3) && in_range(x4, y4) && board[x3][y3] == p && board[x4][y4] == p)
                return p;
        }
    }
    return 0;
}

int main() {
    while(scanf("%d", &n) == 1) {
        memset(board, 0, sizeof(board));
        next_p1 = next_p2 = 0;
        int loser = 0;

        for(int i = 0; i < n * n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if(loser != 0) continue;

            int p = (i&1) + 1;
            board[x][y] = p;
            if(p == 1) {
                p1[next_p1][0] = x;
                p1[next_p1++][1] = y;
            } else {
                p2[next_p2][0] = x;
                p2[next_p2++][1] = y;
            }
            loser = check_loss(p);
        }
        printf("%d\n", loser);
    }
}
