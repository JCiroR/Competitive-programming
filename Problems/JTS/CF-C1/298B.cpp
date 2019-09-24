#include <bits/stdc++.h>
using namespace std;

const int maxs = 700;
int curr[maxs], bef[maxs], d, t, v1, v2;

void solve() {
    for(int ct = 1; ct < t; ct++) {
        for(int k = -d; k <= d; k++) {
            for(int i = 0; i < maxs; i++) {
                if(bef[i] != -1) {
                    if(i + k >= 0 && i + k < maxs)
                        curr[i + k] = max(curr[i + k], bef[i] + (i + k));
                }
            }
        }
        for(int i = 0; i < maxs; i++) bef[i] = curr[i];
    }
}

int main() {
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    memset(curr, -1, sizeof(curr));
    memset(bef, -1, sizeof(bef));
    curr[v1] = bef[v1] = v1;
    solve();
    printf("%d\n", curr[v2]);
}