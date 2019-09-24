#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;
unordered_map<string, int> names;
int id[MAXN], size[MAXN];
int C, R;

void initialize() 
{
    for(int i = 0; i < MAXN; ++i)
    {
        id[i] = i;
        size[i] = 1;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(p == q) return;
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
    names.reserve(7000);
    while(scanf("%d%d", &C, &R) == 2) {
        if(C == 0 && R == 0) break;
        names.clear();
        initialize();
        for(int i = 0; i < C; i++) {
            string curr;
            cin >> curr;
            names[curr] = i;
        }
        for(int i = 0; i < R; i++) {
            string a, b; 
            cin >> a >> b;
            int from = names[b], to = names[a];
            union1(from, to);
        }
        int ans = 0;
        for(int i = 0; i < C; i++) {
            if(i == id[i]) ans = max(ans, size[i]);
        }
        cout << ans << endl;
    }
}