#include <set>
#include <iostream>
#include <cctype>
#include <iterator>
#include <cstring>

using namespace std;

char room[110][110];
bool taken[300];

int main(void) {
    memset(taken, false, sizeof(taken));
    char p;
    int n, m;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> room[i][j];
    taken[p] = true;
    taken['.'] = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(room[i][j] == p) {
                if(i > 0) taken[room[i-1][j]] = true;
                if(i < n - 1) taken[room[i + 1][j]] = true;
                if(j > 0) taken[room[i][j -1]] = true;
                if(j < m - 1) taken[room[i][j + 1]] = true;               
            }
        }
    int d = -2;
    for(int i = 0; i < 300; i++) if(taken[i]) d++;
    cout << d << endl;
}