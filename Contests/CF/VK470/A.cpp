#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
char mat[510][510];
bool possible;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

bool inRange(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    else return true;
}

void fix(int r, int c) {
    for(int d = 0; d < 4; d++) {
        if(!inRange(r + dr[d], c + dc[d])) continue;
        if(mat[r + dr[d]][c + dc[d]] == 'W') possible = false;
        else if(mat[r + dr[d]][c + dc[d]] != 'S') mat[r + dr[d]][c + dc[d]] = 'D';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    possible = true;
    for(int i = 0; i < n && possible; i++)
        for(int j = 0; j < m && possible; j++) {
            if(mat[i][j] == 'S') fix(i, j);
        }
    if(possible) {
        cout << "Yes\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << mat[i][j];
            cout << endl;
        }
    }
    else cout << "No\n";    
}