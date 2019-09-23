//0.12s for N = 30000 and Q = 200k
#include <bits/stdc++.h>
using namespace std;

const int N = 30010;
vector<int> tree[N * 4];
int a[N];

void merge(int p) {
    int l = p << 1, r = (p << 1) + 1;
    int pL = 0, pR = 0;
    int m = tree[l].size() + tree[r].size();
    while(m--) {
        int val;
        if(pL >= tree[l].size()) val = tree[r][pR++];
        else if(pR >= tree[r].size()) val = tree[l][pL++];
        else if(tree[l][pL] < tree[r][pR]) val = tree[l][pL++];
        else val = tree[r][pR++];
        tree[p].push_back(val);
    }
}

void build_tree(int curr, int l, int r) {
    if(l == r) {
        tree[curr].push_back(a[l]);
        return;
    }
    int mid = l + (r - l)/2;
    build_tree(curr<<1, l, mid); //left
    build_tree((curr<<1)+1, mid + 1, r); //right
    merge(curr);
}
// curr segment: [x, y], query: l,r,k
int query(int curr, int l, int r, int x, int y, int k) {
    if(x > r || y < l) return 0;    
    if(x >= l && y <= r)   // Get number of nums in [l, r] greater than k
        return tree[curr].end() - upper_bound(tree[curr].begin(), tree[curr].end(), k);
    
    int mid = x + (y - x)/2;
    return query(curr<<1, l, r, x, mid, k) + query((curr<<1)+1, l, r, mid + 1, y, k);
}

int main() {
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    build_tree(1, 0, n - 1);
    
    int Q; scanf("%d", &Q);
    int lastAns = 0, a, b, c;
    for(int q = 0; q < Q; q++) {
        scanf("%d%d%d", &a, &b, &c);
        int i, j, k;
        i = a^lastAns;
        j = b^lastAns;
        k = c^lastAns;

        if(i < 1) i = 1;
        if(j > n) j = n;
        
        if(i > j) lastAns = 0;
        else {
            i--, j--;
            lastAns = query(1, i, j, 0, n - 1, k);
        }
        printf("%d\n", lastAns);
    }
}