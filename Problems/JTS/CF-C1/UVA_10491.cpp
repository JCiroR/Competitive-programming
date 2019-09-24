#include <bits/stdc++.h>
using namespace std;

int main() {
    double V, C, S;
    while(cin >> V >> C >> S)
    {
        double N = V + C;
        double O = N - S - 1;
        double ans = C * (N - 1);
        ans /= (N * O);
        printf("%.5lf\n", ans);
    }
}