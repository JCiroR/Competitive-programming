#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double err = 0.00001;

double evaluate(double p, double q, double r, double s, double t, double u,double x) {
    return p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x +u;
}

bool checkZero(double num) {
    return (abs(0.0 - num) < err);
}

int main(void) {
    double p, q, r, s, t, u;
    while(cin >> p >> q >> r >> s >> t >> u) {
        double first = evaluate(p, q, r, s, t, u, 0);
        double second = evaluate(p, q, r, s, t, u, 1);
        if (first * second > 0) {
            cout << "No solution\n";
            continue;
        }
        double low = 0.0, hi = 1.0, mid = 0.0, answ = 0.0;
        for(int i = 0; i < 100; i++) {
            mid = (low + hi)/2.0;
            double mid_val = evaluate(p,q,r,s,t,u,mid);
            if(checkZero(mid_val)) answ = mid;
            if(first < 0) {
                if(mid_val < 0) low = mid;
                else hi = mid;
            } else {
                if(mid_val < 0) hi = mid;
                else low = mid;
            }
        }
        cout << setprecision(4) << fixed << answ << endl;
    }
    return 0;
}