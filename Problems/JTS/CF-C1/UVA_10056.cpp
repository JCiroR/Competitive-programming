#include <bits/stdc++.h>
using namespace std;

const double e = 0.000000001;

int main() {
    int t; scanf("%d", &t);
    while(t--)
    {
        double n, p, i;
        scanf("%lf %lf %lf", &n, &p, &i);
        if(p == 0.0 || n == 0) {
            printf("%.4lf\n", 0.0);
            continue;
        }
        double np = 1 - p;
        double cp = pow(np, i - 1), pf = pow(np, n - 1);
        double delta = 0, ans = 0;
        do {
            delta = cp * p;
            ans += delta;
            cp *= np;
            cp *= pf;
        } while (delta > e);
        printf("%.4lf\n", ans);
    }
}