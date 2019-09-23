//https://www.spoj.com/problems/MATGAME/
#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int mat[N][N];
int t, n, m;

int main () {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        int xorSum = 0;
        for(int i = 0; i < n; i++) {
            int grundy = mat[i][m-1];
            for(int j = m - 2; j >= 0; j--) {
                if(mat[i][j] > grundy) grundy = mat[i][j];
                else grundy = mat[i][j] - 1;
            }
            xorSum ^= grundy;
        }
        cout << (xorSum?"FIRST":"SECOND") << endl;
    }
}
