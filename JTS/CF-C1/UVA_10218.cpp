#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double comb[110][110];

void fill() {
    for(ll n = 0; n <= 100; n++) {
        comb[n][n] = 1;
        for(ll c = 1; c <= n; c++) {
            comb[n][n - c] = (n - c + 1) * comb[n][n - c + 1];
            comb[n][n - c] /= c;
        }
    }
}

int main() {
    double m, w;
    int c;
    while(scanf("%lf%lf%d", &m,&w,&c) == 3) {
        if(m == 0 && w == 0) break;
        double pm = m / (m + w), pw = w / (m + w);
        double ans = 0;
        for(int x = 0; x <= c; x += 2)
        {
            ans += pow(pw, c - x) * pow(pm, x) * comb[c][x];
        }
        printf("%.7lf\n", ans);
    }
}