#include <bits/stdc++.h>
using namespace std;

double pi[21], pic[21], ans[21];

int main() {
    int n, r, test = 1;
    while(scanf("%d%d", &n, &r) == 2 && (n || r)) {
        fill(ans, ans + 21, 0.0);
        printf("Case %d:\n", test++);
        for(int i = 0; i < n; i++) {
            scanf("%lf", &pi[i]);
            pic[i] = 1 - pi[i];
        }
        int lim = (1 << n) - 1;
        double tot = 0;
        while(lim) {
            double curr = 1;
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(lim & (1 << i)) {
                    count++;
                    curr *= pi[i];
                } else curr *= pic[i];
            }
            if(count == r) {
                tot += curr;
                for(int i = 0; i < n; i++)
                    if(lim & (1 << i)) ans[i] += curr;
            }
            lim--;
        }
        for(int i = 0; i < n; i++) {
            double out;
            if(tot > 0) out = ans[i]/tot;
            else out = 0.0;
            printf("%.6lf\n", out);
        }
            
    }
}