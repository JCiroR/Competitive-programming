#include <iostream>
#include <string>
#include <map>

using namespace std;
const int MAXN = 2000020;
int id[MAXN], size[MAXN];
map<string, int> names;

void initialize() {
    for(int i = 0; i < MAXN; ++i) {
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

int setSize(int x) {
    x = root(x);
    return size[x];
}

int main() {
    int T; cin >> T;
    while(T--) {
        names.clear();
        int F; cin >> F;
        initialize();
        string a, b;
        int index = 0, a_i, b_i;
        while(F--) {
            cin >> a >> b;
            if(names.count(a) == 0) names[a] = index++;
            if(names.count(b) == 0) names[b] = index++;
            a_i = names[a];
            b_i = names[b];
            int p = root(a_i), q = root(b_i);
            if(p != q) union1(p, q);
            cout << setSize(p) << endl;
        }
    }
}