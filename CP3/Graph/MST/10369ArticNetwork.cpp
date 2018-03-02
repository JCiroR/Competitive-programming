#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;
const int MAXN = 501;

pair<float, pair<int,int> >p[MAXN * MAXN];
int id[MAXN], size[MAXN], coord[MAXN][2];
int n, s;

void initialize() {
    for(int i = 0; i <= n; i++) {
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
        size[p] += size[q];
    }
}

float kruskal(int edges) {
    int x, y;
    float cost, D = 0.0;
    int trees = n;
    for(int i = 0; i < edges; i++) { 
        if(trees == s) break;
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)) {
            D = cost;
            union1(x,y);
            trees--;
        }
    }
    return D;
}

float get_w(int x1, int y1, int x2, int y2) {
    float a = (float)((x1 - x2)*(x1 - x2));
    float b = (float)((y1 - y2)*(y1 - y2));
    return  sqrt(a + b);
}

int main() { 
    int T;
    cin >> T;
    while(T--) {
        cin >> s >> n;
        int x, y;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            coord[i][0] = x;
            coord[i][1] = y;
        }
        int next = 0;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            float w = get_w(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
            p[next] = make_pair(w, make_pair(i,j));
            next++;
        }
        initialize();
        sort(p, p + next);
        float min_dist = kruskal(next);
        printf("%.2lf\n", min_dist);
    }
    return 0;
}