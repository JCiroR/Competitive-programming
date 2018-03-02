#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

double eval(double r1, double p1, double p2, double A, double B) {
    return r1 * sqrt(B * p1 / (p2 * A + p1 * B));
}

int main() {
    int n, m, k, temp;
    int r1 = -1, p1 = -1, p2 = INT_MAX, A, B;
    cin >> n;
    while(n--) {
        cin >> temp;
        r1 = max(temp, r1);
    }
    cin >> m;
    while(m--) {
        cin >> temp;
        p1 = max(p1, temp);
    }
    cin >> k;
    while(k--) {
        cin >> temp;
        p2 = min(temp, p2);
    }
    cin >> A >> B;
    printf("%.12f\n", eval(r1, p1, p2, A, B));
}
