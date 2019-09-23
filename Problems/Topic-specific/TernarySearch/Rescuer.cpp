//https://www.hackerearth.com/problem/algorithm/rescuer-1/description/
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
double x1, y_1, x2, y2, v1, v2;

double evaluate(double x) {
    double eval = hypotl(abs(x1 - x), y_1) / v1;
    eval += hypotl(abs(x2 - x), y2) / v2;
    return eval;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y_1, &x2, &y2, &v1, &v2);
        double l = min(x1, x2), r = max(x1, x2), m1, m2, f1, f2;
        int it = 0;
        while(r - l > eps && it < 500) {
            m1 = l + (r-l)/3;
            m2 = r - (r-l)/3;
            f1 = evaluate(m1);
            f2 = evaluate(m2);
            if(f1 < f2) 
                r = m2;
            else 
                l = m1;
            it++;
        }
        double ans = evaluate(l);
        printf("%.5lf\n", ans);
    }
}