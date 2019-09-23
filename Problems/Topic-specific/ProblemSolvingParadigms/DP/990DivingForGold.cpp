#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30;
const int MAXT = 1000;

int depth[MAXN], value[MAXN], taken[MAXT], knap[MAXT + 1], recovered[MAXT + 1];
int t, w, n, max, max_index;

void func() {
    knap[0] = 0;
    for(int i = 0; i < n; i++) for(int j = t; j >= 0; j--) {
        int weight = 3*depth[i]*w;
        if(knap[j] != -1 && j + weight <= t) {
            if(knap[j + weight] < knap[j] + value[i]) {
                knap[j + weight] = knap[j] + value[i];
                taken[j + weight] = taken[j] | (1 << i);
                recovered[j + weight] = recovered[j] + 1;
                if(knap[j + weight] > max) {
                    max = knap[j + weight];
                    max_index = j + weight;
                }
            }
        }
    }
}

int main(void) {
    int T = 0;
    while(scanf("%d %d", &t,&w)==2) {
        T++;
        if(T > 1) printf("\n");
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &depth[i], &value[i]);
        }
        max = 0;
        max_index = 0;
        memset(taken, 0, sizeof(taken));
        memset(recovered, 0, sizeof(recovered));
        memset(knap, -1, sizeof(knap));
        func();
        printf("%d\n%d\n", max, recovered[max_index]);
        for(int i = 0; i < n; i++) {
            if(taken[max_index] & (1 << i)) printf("%d %d\n", depth[i],value[i]);
        }
    }
    return 0;
}