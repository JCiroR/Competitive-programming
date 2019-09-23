#include <cstdio>

using namespace std;

double check(int n, double H1, double H2) {
    double H;
    for(int i = 3; i <= n; i++) {
        H = 2 * H2 + 2 - H1;
        if(H < 0) return -1;
        H1 = H2;
        H2 = H;
    }
    return H;
}

int main() {
    int n;
    double A;
    while(scanf("%d %lf", &n, &A) == 2) {
        double l = 0, r = A, ans = A, mid, t;
        for(int it = 0; it < 100; it++) {
            mid = (l + r)/2;
            if((t = check(n, A, mid)) >= 0)
                r = mid, ans = t;
            else
                l = mid;
        }
        printf("%.2f\n", ans);
    }
}