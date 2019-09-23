#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n, m, k;

bool eval(int num) {
    int need = 0;
    int currBx = 0;
    for(int i = num; i < n; i++) {
        if(currBx - a[i] < 0) {
            currBx = k;
            need++;
        }
        currBx -= a[i];
    }
    return need <= m;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int best = n;
    int l = 0, r = n;
    while(l <= r) {
        int mid = l + (r - l)/2;
        // printf("l: %d r: %d mid: %d\n", l, r, mid);
        if(eval(mid)) {
            best = min(best, mid);
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << n - best << endl;
}