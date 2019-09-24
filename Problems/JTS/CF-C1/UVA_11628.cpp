#include <bits/stdc++.h>
using namespace std;

int b[10100];

// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        int temp, tot = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &temp);
                if(j == m - 1) b[i] = temp, tot += temp;
            }
        }
        for(int i = 0; i < n; i++) {
            if(b[i] == 0) printf("0 / 1\n");
            else {
                int g = __gcd(b[i], tot);
                printf("%d / %d\n", (b[i]/g), (tot/g));
            }
        }
    }
}