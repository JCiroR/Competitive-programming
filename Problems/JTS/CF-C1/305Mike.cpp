#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int mat[501][501];
int score[501];

int main() {
    int n, m, q;
    scanf("%d %d %d\n", &n, &m, &q);
    for(int i = 0; i < n; i++) {
        int curr = 0, max_c = 0;
        for(int j = 0; j < m; j++) {            
            scanf("%d", &mat[i][j]);
            if(mat[i][j] == 1) curr++;
            else curr = 0;
            max_c = max(curr, max_c);
        }
        score[i] = max_c;
    }
    int x, y;
    while(q--) {
        scanf("%d %d", &x, &y);
        x--, y--;
        mat[x][y] ^= 1;
        int curr = 0, max_c = 0;
        for(int j = 0; j < m; j++) {
            if(mat[x][j] == 1) curr++;
            else curr = 0;
            max_c = max(max_c, curr);
        }
        score[x] = max_c;
        for(int i = 0; i < n; i++) max_c = max(max_c, score[i]);
        printf("%d\n", max_c);
    }
}