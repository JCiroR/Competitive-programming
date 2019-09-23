#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> tree[N*4];
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
    build_tree((curr<<1)+1, mid + 1, r);
    merge(curr);
}

bool present;
int query(int curr, int l, int r, int x, int y, int k) {
    if(x > r || y < l) return 0;
    if(x >= l && y <= r) {
        if(binary_search(tree[curr].begin(), tree[curr].end(), k)) present = true;
        return lower_bound(tree[curr].begin(), tree[curr].end(), k) - tree[curr].begin();
    }
    int mid = x + (y - x)/2;
    return query(curr<<1, l, r, x, mid, k) + query((curr<<1)+1,l,r,mid+1,y,k);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    build_tree(1, 0, n-1);
    sort(a, a + n);
    int i, j, k;
    for(int c = 0; c < m; c++) {
        scanf("%d%d%d", &i, &j, &k);
        i--, j--;
        int l = 0, r = n - 1, mid, ans;
        while(l <= r) {
            present = false;
            mid = l + (r - l)/2;
            int eval = query(1, i, j, 0, n - 1, a[mid]);
            if(eval == k - 1) {
                ans = mid;
                if(present) break;
                l = mid + 1;
            } else if(eval < k - 1) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", a[ans]);
    }
}