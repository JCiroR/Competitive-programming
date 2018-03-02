#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAXN = 1000001;

pair<long long, pair<int,int> >p[MAXN];
int id[MAXN], size[MAXN];
int n,m;

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

long long kruskal() {
    int x, y;
    long long cost, largestCost = 0;
    int addedEdges = 0;
    for(int i = 0; i < m; i++) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)) {
            largestCost = cost;
            union1(x,y);
            addedEdges++;
        }
    }
    if(addedEdges < n-1) return -1;
    else return largestCost;
}

int main() { 
    while(cin >> n >> m  && (n || m)) {
        initialize();   
        int x, y;
        long long weight;
        for(int i = 0; i < m; i++) {
            cin >> x >> y >> weight;
            p[i] = make_pair(weight, make_pair(x, y));
        }
        sort(p, p + m);
        long long largest = kruskal();
        if(largest < 0) cout << "IMPOSSIBLE\n";
        else cout << largest << endl;
    }
    return 0;
}