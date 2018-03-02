#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 200001;
pair <int, pair<int, int> > p[MAXN];
int id[MAXN], size[MAXN];

int m, n;

void initialize() {
    for(int i = 0; i < m; i++) {
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

long long kruskal() {
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i < n; ++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y)) {
            minimumCost += cost;
            union1(x,y);
        }
    }
    return minimumCost;
}

int main() {
    while(cin >> m >> n) {
        if(m == 0 && n == 0) break;
        int x, y, z;
        long long before = 0;
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            p[i] = make_pair(z, make_pair(x, y));
            before += z;
        }
        initialize();
        sort(p, p + n);
        long long after = kruskal();
        cout << before - after << endl;
    }
    return 0;
}