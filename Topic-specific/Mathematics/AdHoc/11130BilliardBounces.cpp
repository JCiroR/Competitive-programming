#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;

int main(void) {
    double a, b, v, A, s;
    while(cin >> a >> b >> v >> A >> s && a > 0) {
        double vx = v * cos(A * PI / 180), vy = v * sin(A * PI/ 180);
        double ax = -vx / s, ay = -vy / s;

        double dx = vx * s + 0.5 * ax * s * s;
        double dy = vy * s + 0.5 * ay * s * s;

        int vb = (dx + a / 2) / a;
        int hb = (dy + b / 2) / b;

        cout << vb << " " << hb << endl;
    }

    return 0;
}