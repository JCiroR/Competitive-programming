#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const pii nullPii = pii(-1, -1);
pii dp[20][20][400];
bool seen[20][20];
int r, c;

void printAns(int i, int j, int visited) {
    printf("%d %d\n", i + 1, j + 1);
    pii next = dp[i][j][visited];
    if(visited + 1 == r*c) return;    
    printAns(next.first, next.second, visited + 1);
}

bool fun(int i, int j, int visited) {
    // printf("%d %d %d\n", i, j, visited);
    if(visited + 1 == r*c) return true;
    seen[i][j] = true;
    for(int k = 0; k < r; k++)
        for(int l = 0; l < c; l++) {
            if(seen[k][l] || k == i || l == j || (i - j) == (k - l) || (i + j) == (k + l))
                continue;
            if(fun(k, l, visited + 1)) {
                dp[i][j][visited] = pii(k, l);
                return true;
            }
        }
    dp[i][j][visited] = nullPii;
    seen[i][j] = false;
    return false;
}

int main() {
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &r, &c);
        memset(seen, false, sizeof(seen));
        fill_n(&dp[0][0][0], 20*20*400 , nullPii);
        
        bool possible = false;
        int ansI = -1, ansJ = -1;
        for(int i = 0; !possible && i < r; i++)
            for(int j = 0; !possible && j < c; j++)
                if(fun(i, j, 0)) {
                    possible = true;
                    ansI = i, ansJ = j;
                }
            
        printf("Case #%d: ", t);
        if(possible) {
            printf("POSSIBLE\n");
            printAns(ansI, ansJ, 0);
        }
        else printf("IMPOSSIBLE\n");
    }
}
