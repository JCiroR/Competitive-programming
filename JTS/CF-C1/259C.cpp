#include <iostream>
#include <cstdio>
using namespace std;

double fast_exp(double a, int y) {
    double res = 1;
    while(y) {
        if(y & 1) res *= a;
        a *= a;
        y >>= 1;
    }
    return res;
}

int main() {
    int n, m; 
    cin >> m >> n;
    double last = 0, ans = 0, md = m, nd = n;
    for(double i = 1; i <= m; i++) {
        double curr = i/md;
        curr = fast_exp(curr, n);
        ans += i * (curr - last);
        last = curr;
    }
    printf("%.12lf\n", ans);
}