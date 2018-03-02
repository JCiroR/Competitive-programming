#include <cstdio>
#include <cstring>

using namespace std;


const int MAXN = 101, mod = 1000000;
int mem[MAXN][MAXN];

int ways(int n, int k) {
    if(n < 0) return 0;
    if(k == 1) return 1;
    if(mem[n][k] != -1) return mem[n][k];
    int cont = 0;
    for(int i = 0; i <= n; i++) {
        cont = (cont % mod) + (ways(n - i, k - 1) % mod);
        cont %= mod;
    }
    return mem[n][k] = cont;
}

int main(void) {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2 && (n || k)) {
        memset(mem, -1, sizeof(mem));
        printf("%d\n", ways(n, k));
    }
    return 0;
}