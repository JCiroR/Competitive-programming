#include <bits/stdc++.h>

using namespace std;

char matC[101][10010];
int mat[101][10010], n, m;

int main() {
    scanf("%d %d\n", &n, &m);
    bool pos = true;
    for(int i = 0; i < n; i++) scanf("%s\n", &matC[i][0]);
    for(int i = 0; i < n; i++) {
        bool found = false;
        int closest = -1;
        for(int j = 0; j < 2*m; j++) {
            if(matC[i][j%m] == '1') {
                closest = 0;
                found = true;
            }
            if(closest >= 0) {
                mat[i][j%m] = closest;
                closest++;
            } else mat[i][j%m] = 10000*100;
        }
        if(!found) pos = false;
    }
    if(pos) {
        for(int i = 0; i < n; i++) {
            int closest = -1;
            for(int j = 2*m; j >= 0; j--) {
                if(matC[i][j%m] == '1') closest = 0;
                if(closest >= 0) {
                    mat[i][j%m] = min(mat[i][j%m], closest);
                    closest++;
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) cout << mat[i][j] << " ";
        //     cout << endl;
        // }
        long long ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            long long currC = 0;
            for(int j = 0; j < n; j++)
                currC += mat[j][i];
            ans = min(ans, currC);
        }
        cout << ans << endl;
    } else cout << -1 << endl;
}