#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

const int MAXN = 2010;

bool mat[MAXN][MAXN];
int res[MAXN][MAXN], n, m, k;
queue<pair<int,pair<int,int> > > s;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

bool inRange(pair<int,int> p) {
    return(p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}

void bfs() {            
    while(!s.empty()) {
        pair<int, pair<int,int> > p = s.front();
        s.pop();
        res[p.second.first][p.second.second] = min(res[p.second.first][p.second.second], p.first);
        for(int d = 0; d < 4; d++) {
            pair<int, pair<int,int> > opt = make_pair(p.first + 1, make_pair(p.second.first + dr[d], p.second.second + dc[d]));
            if(inRange(opt.second) && !mat[opt.second.first][opt.second.second]) {                
                mat[opt.second.first][opt.second.second] = true;
                s.push(opt);
            }                
        }
    }
}

int main() {
    ifstream ifs("input.txt", ifstream::in);
    ifs >> n >> m >> k;
    int x, y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[i][j] = 1000000;
    memset(mat, false, sizeof(mat));        
    while(k--) {
        ifs >> x >> y;
        s.push(make_pair(0, make_pair(x-1, y-1)));    
        mat[x-1][y-1] = true;        
    }
    bfs();
    ifs.close();
    int t_max = 0, x_max = x, y_max = y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(res[i][j] > t_max) {
                x_max = i + 1;
                y_max = j + 1;
                t_max = res[i][j];
            }
        }
    ofstream ofs("output.txt", ofstream::out);
    ofs << x_max << " " << y_max << endl;    
    ofs.close();
}
