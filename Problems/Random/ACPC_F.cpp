//https://open.kattis.com/contests/acpc18open/problems/pubnite
#include <bits/stdc++.h>
using namespace std;

double xs, ys, ss, ri, rf;
double xa, ya, sa;

double timeToReach(double dis, double scape, double reach) {
    return dis/(reach - scape);
}

int main() {
    cin >> xs >> ys >> ss >> ri >> rf;
    cin >> xa >> ya >> sa;

    double r3 = hypot(xs - xa, ys - ya);
    double p1 = xs + rf, p2 = xs + ri, p3 = xs + r3;
    double t_cerr = abs(p3 - p1)/sa;
    double ans = -1;
    if(p3 <= p1) ans = 0;
    else if(p3 <= p2) {
        if(sa >= ss) ans = 0;
        else {
            double t = timeToReach(abs(p2 - p3), sa, ss);
            if(t >= t_cerr) ans = 0;
            else {
                p3 -= t * sa;
                p2 -= t * ss;
                t_cerr -= t;
                ans = t_cerr;
            }
        }
    } else if(sa <= ss) ans = t_cerr;
    else {
        double t = timeToReach(abs(p2 - p3), ss, sa);
        ans = min(t_cerr, t);
    }
    printf("%.6f\n", ans);
}
