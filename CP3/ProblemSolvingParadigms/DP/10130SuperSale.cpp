#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXW = 30;
const int MAXN = 1001;

int price[MAXN], weight[MAXN], knap[MAXW + 1], answ[MAXW + 1], n;

void func() {
    knap[0] = 0;
    for(int i = 0; i < n; i++) for(int j = MAXW; j >= 0; j--) {
        if(knap[j] != -1 && weight[i] + j <= MAXW) {
            knap[weight[i]+j] = max(knap[weight[i]+j], knap[j] + price[i]);
        }
    }
}

int main(void) {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d %d", &price[i], &weight[i]);
        memset(knap, -1, sizeof(knap));
        memset(answ, 0, sizeof(answ));
        func();
        int currMax = -1;
        for(int i = 0; i <= MAXW; i++) {
            answ[i] = max(knap[i], currMax);
            currMax = answ[i];
        }
        int G, MW, total = 0;
        scanf("%d", &G);
        while(G--) {
            scanf("%d", &MW);
            total += answ[MW];
        }
        printf("%d\n", total);
    }
}
