#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int mat[maxn][maxn], sum = 0,  n, q;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if(i == j) sum += mat[i][j];
        } 
    scanf("%d", &q);
    int op, row; 
    while(q--) {
        scanf("%d", &op);
        if(op == 3) printf("%d", (sum % 2));
        else {
            scanf("%d", &row);
            int * v = &mat[row-1][row-1];
            sum -= *v;
            *v ^= 1;
            sum += *v;
        }
    }
    printf("\n");
}
