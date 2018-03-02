#include <iostream>
#include <cstring>

using namespace std;

bool row[110], col[110];
int mat[110][110];


int main() {
    int n, m, temp;
    cin >> n >> m;
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    bool ok = true;
    int rows_c = 0, cols_c = 0;
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 1) count++;
        if(count == m) {            
            row[i] = true;
            rows_c++;        
        }
    }
    for(int j = 0; j < m; j++) {
        int count = 0;
        for(int i = 0; i < n; i++)
            if(mat[i][j] == 1) count++;
        if(count == n) {
            col[j] = true;
            cols_c++;
        }
    }
    if((cols_c > 0 && rows_c == 0) || (rows_c > 0 && cols_c == 0)) ok = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 1 && !row[i] && !col[j]) ok = false;            
    if(!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j > 0) cout << " ";
                if(row[i] && col[j]) cout << '1';
                else cout << '0';
            }
            cout << endl;
        }
    }
}