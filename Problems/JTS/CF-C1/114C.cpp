#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double a, d, t, vf;
    scanf("%d %lf %lf", &n, &a, &d);
    double bestP = -1;
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &t, &vf);
        double t1 = vf / a;
        if((vf*vf)/(2*a) >= d) t1 = sqrt(2.0 * d/a);
        else {
            double drest = d - (vf*vf)/(2*a);
            t1 += drest/vf;
        }
        double currP = t + t1;
        if(currP < bestP) currP = bestP;
        bestP = currP;
         printf("%.10lf\n", currP);
    }       
}