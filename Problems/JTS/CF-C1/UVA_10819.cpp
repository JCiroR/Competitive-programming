#include <bits/stdc++.h>
using namespace std;

const int MAXB = 11000;
int n, m, p, f, knap[MAXB];
pair<int,int> item[110];

void solve() {
    for(int k = 0; k < n; k++) {
        pair<int,int> p1 = item[k];
        for(int j = MAXB - 1; j >= 0; j--) {
            if(knap[j] != -1 && j + p1.first < MAXB) {
                knap[j + p1.first] = max(knap[j + p1.first], knap[j] + p1.second);
            }
        }
    }
}

int main() {
    while(scanf("%d%d", &m, &n) == 2) {
        for(int i = 0; i < n; i++) {
          scanf("%d%d", &p, &f);
          item[i].first = p;
          item[i].second = f;
        }
        memset(knap, -1 , sizeof(knap));
        knap[0] = 0;
        solve(); 
        int ans = 0, free = 0;
        for(int i = 0; i < MAXB; i++) {
           if(i > 2000) free = 200;
           if(i <= m + free) ans = max(knap[i], ans);
        }
        printf("%d\n", ans);
    }
}