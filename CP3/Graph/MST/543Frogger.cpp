#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 203;
int id[MAXN], size[MAXN];
int coord[MAXN][2];
bool visited[MAXN];
vector<pair<float, pair<int,int> > >p;
vector<pair<float, int> > mst[MAXN];


void initialize() {
    for(int i = 0; i < MAXN; i++) {
        id[i] = i;
        size[i] = 1;
    }
}

int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    if(size[p] < size[q]) {
        id[p] = id[q];
        size[q] += size[p];
    } else {
        id[q] = id[p];
        size[p] = size[q];
    }
}

void kruskal() {
    int x, y;
    float cost;
    for(int i = 0; i < p.size(); ++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)) {
            union1(x, y);
            mst[x].push_back(make_pair(cost, y));
            mst[y].push_back(make_pair(cost, x));
        }
    }
}

float get_w(int x1, int y1, int x2, int y2) {
    float a = (float)((x1 - x2)*(x1 - x2));
    float b = (float)((y1 - y2)*(y1 - y2));
    return  sqrt(a + b);
}

float dfs(int s) {
    visited[s] = true;
    //cout << "s: " << s << "mst.s: " << mst[s].size() << endl;
    for(int i = 0; i < mst[s].size(); i++) {
        float w = mst[s][i].first;
        int c = mst[s][i].second;
        if(!visited[c]) {
            
            if(c == 1) return w;
            float opt = dfs(c);
            if(opt >= 0.0) return max(w, opt);
        }
    }
    return -1.0;        
}
    

int main(void) {
    int T = 1, n;
    while(cin >> n) {
        if(n == 0) break;
        cout << "Scenario #" << T << endl;
        T++;
        p.clear();
        for(int i = 0; i <= n; i++) mst[i].clear();
        int x, y;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            coord[i][0] = x;
            coord[i][1] = y;
        }
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            float w = get_w(coord[j][0], coord[j][1], coord[i][0], coord[i][1]);
            p.push_back(make_pair(w, make_pair(i, j)));
        }
        sort(p.begin(), p.end());
        initialize();
        kruskal();
        memset(visited, false, sizeof(visited));
        printf("Frog Distance = %.3lf\n\n", dfs(0));
    }
}