#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 110; 
int n, m, Mat[N][N];


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int xorA = 0, xorB= 0;
    for(int i = 0; i < n; i++) {
        cin >> Mat[i][0];
        xorA ^= Mat[i][0];
    }
    for(int i = 0; i < m; i++) {
        if(i == 0) cin >> xorB;
        else {
            cin >> Mat[0][i];
            xorB ^= Mat[0][i];
            Mat[0][0] ^= Mat[0][i];
        }
    }
    if(xorA == xorB) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j > 0) cout << " ";
                cout << Mat[i][j];
            }
            cout << endl;
        }
    } else cout << "NO\n";
}