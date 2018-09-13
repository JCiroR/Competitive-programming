#include <bits/stdc++.h>
using namespace std; 

double prob[100010];

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l,&r);
        int nr = r - r%p, nl = (l/p);
        nl *= p;
        if(nl < l) nl += p;
        int times = (nr / p) - (nl / p) + 1;
        prob[i] = (double)times/((double)r - l + 1);
        
    }
    for(int i = 0; i < n; i++)
    {
        int s = (i + 1) % n;
        ans += (2000.0 * (prob[i] + prob[s] - prob[i]*prob[s]));
    }
    printf("%.7lf\n", ans);
}