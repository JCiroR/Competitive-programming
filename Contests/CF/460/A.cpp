#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int cost[5010];
int kilos[5010];

double getAns(double a, double b, double m) {
    return a * m / b;
}
int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        cin >> kilos[i];
    }
    double cheap = 100 * 100000;
    for(int i  = 0; i < n; i++)
        cheap = min(cheap, getAns(cost[i], kilos[i], m));
    printf("%.8f\n", cheap);
}


