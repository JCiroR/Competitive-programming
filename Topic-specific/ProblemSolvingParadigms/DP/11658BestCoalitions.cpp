#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAXN = 100, MAXP = 100*100;

int n, x;
int p[MAXN];
bool knap[MAXP + 1];
int bestP;

void func() {
    for(int i = 0; i < n; i++) {
        if(i == x) continue;
        for(int j = MAXP; j >= p[x]; j--) {
            if(knap[j] && j + p[i] <= MAXP) {
                knap[j + p[i]] = true;
                if(j + p[i] > 5000 && j + p[i] < bestP) bestP = j + p[i];                 
            }
        }
    }
}

int main(void) {
    while(scanf("%d %d", &n, &x) == 2 && (n && x)) {
        x--;
        int a, b;
        for(int i = 0; i < n; i++) {
            scanf("%d.%d", &a, &b);
            p[i] = a * 100 + b;
        }
        if(p[x] > 5000) {
            printf("100.00\n");
            continue;
        }
        bestP = 100*100;
        memset(knap, false, sizeof(knap));
        knap[p[x]] = true;
        func();
        printf("%.2lf\n", (100.0 * (double)p[x])/(double)bestP);
    }
    return 0;
}
