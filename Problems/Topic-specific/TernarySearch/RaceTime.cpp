//https://www.codechef.com/problems/AMCS03
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
double d[N], s[N];
const double INF = 1e11;
int n;

double eval(double t) {
    double maxF = 0, minF = INF;
    for(int i = 0; i < n; i++) {
        double f = s[i] * t + d[i];
        maxF = max(maxF, f);
        minF = min(minF, f);
    }
    return maxF - minF;
}

int main() {
    double k;
    scanf("%d %lf",&n,&k);
    for(int i = 0; i < n; i++)
        scanf("%lf %lf", &s[i], &d[i]);
    double l = 0, r = k, m1, m2, f1, f2;
    int it = 0;
    while(it < 100) {
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;
        f1 = eval(m1);
        f2 = eval(m2);
        if(f1 < f2)
            r = m2;
        else
            l = m1;
        it++;
    }
    printf("%.6lf\n", eval(l));   
}