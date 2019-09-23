#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 1e3 + 10;
char mat[N][N];
int n, m;

bool ink(int i, int j) {
    return mat[i][j] == '#';
}

int dr[] = {1, 1,0,-1,-1,-1, 0, 1}; 
int dc[] = {0, 1,1, 1, 0,-1,-1,-1}; 
bool validCenter(int i, int j) {
    if(i - 1 < 0 || j - 1 < 0 || i + 1 >= n || j + 1 >= m) return false;
    for(int d = 0; d < 8; d++) {
        if(!ink(i + dr[d], j + dc[d])) return false;
    }
    return true;
}

bool check(int i, int j) {
    for(int d = 0; d < 8; d++)
        if(validCenter(i + dr[d], j + dc[d])) return true;
    return false;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s\n", &mat[i][0]);
    }
    bool ans = true;
    for(int i = 0; i < n && ans; i++)
        for(int j = 0; j < m && ans; j++)
            if(mat[i][j] == '#' && !check(i, j)) ans = false;        
    if(ans) printf("YES\n");
    else printf("NO\n");
}