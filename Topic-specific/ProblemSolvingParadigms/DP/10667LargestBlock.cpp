#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 103;
const int occupied = -200000;
int board[MAXN][MAXN];
int sumB[MAXN][MAXN];

void reset(int size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++) {
            board[i][j] = 1;
            sumB[i][j] = 0;
        }
}

void occupy(int r1, int c1, int r2, int c2) {
    for(int i = r1; i <= r2; i++)
        for(int j = c1; j <= c2; j++)
            board[i][j] = occupied;
}

int main(void) {
    int p;
    cin >> p;
    while(p--) {
        int size, blocks;
        cin >> size >> blocks;
        reset(size);

        int r1, c1, r2, c2;
        while(blocks--) {
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            occupy(r1, c1, r2, c2);
        }

        for(int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                sumB[i][j] = board[i][j];
                if(i > 0) sumB[i][j] += sumB[i-1][j];
                if(j > 0) sumB[i][j] += sumB[i][j-1];
                if(i > 0 && j > 0)  sumB[i][j] -= sumB[i-1][j-1];
            }
        }

        int maxSubRect = INT_MIN;
        for(int i = 0; i < size; i++) for(int j = 0; j < size; j++)
        for(int k = i; k < size; k++) for(int l = j; l < size; l++) {
            int subRect = sumB[k][l];
            if(i > 0) subRect -= sumB[i-1][l];
            if(j > 0) subRect -= sumB[k][j-1];
            if(i > 0 && j > 0) subRect += sumB[i-1][j-1];
            if(maxSubRect < subRect) maxSubRect = subRect;
        }         

        if(maxSubRect > 0) cout << maxSubRect << endl;
        else cout << 0 << endl;
    }
}