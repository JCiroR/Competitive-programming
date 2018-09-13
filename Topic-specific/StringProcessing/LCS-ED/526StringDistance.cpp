#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 85;

int M[MAXN][MAXN], n, m;
string a,b;

void getAnsw() {
    int step = 0;
    int i = n, j = m;
    while(i || j) {
        //cout << "i: " << i << " j: " << j << endl;
        //cout << M[j][i] << endl;
        if(a[i-1] == b[j-1]) {
            i--, j--;
            continue;
        }
        printf("%d ", ++step);
        if(i > 0 && M[j][i] == M[j][i-1] + 1) {
            printf("Delete %d", i);
            a.erase(i - 1, 1);
            i--;
        } else if(j > 0 && M[j][i] == M[j-1][i] + 1) {
            printf("Insert %d,%c", i+1, b[j-1]);
            a.insert(i, 1, b[j-1]);
            j--;
        } else if(i > 0 && j > 0) {
            printf("Replace %d,%c", i, b[j-1]);
            a[i-1] = b[j-1];
            i--; j--;   
        }
        cout << "\n";   
    }
}

int main(void) {
    int T = 0;
    while(getline(cin, a) && getline(cin, b)) {
        T++;
        if(T > 1) cout << endl;
        n = a.size(); 
        m = b.size();
        M[0][0] = 0;
        for(int i = 1; i <= n; i++)  M[0][i] = i;
        for(int i = 1; i <= m; i++) M[i][0] = i;

        for(int i = 1; i <= m; i++) 
            for(int j = 1; j <= n; j++) {
                int rCost = M[i-1][j-1];
                if(a[j-1] != b[i-1]) rCost++;
                M[i][j] = min(M[i][j-1] + 1, M[i-1][j] + 1);     
                M[i][j] = min(M[i][j], rCost);
            }
        /*for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                printf("%d ", M[i][j]);
            }
            cout << endl;
        }*/
        cout << M[m][n] << endl;
        getAnsw();
    }
    return 0;
}