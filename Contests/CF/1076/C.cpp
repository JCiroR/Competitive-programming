#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const double EPS = 1e-6;

int main(void) {
   int t; cin >> t;
   while(t--) {
        double d; cin >> d;
        
        double disc = d*d - 4 * d;
        if(disc < 0) printf("N\n");
        else {
            double x = -d + sqrt(disc);
            x /= 2.0;

            double b = -x;
            double a = d - b;
            if(a >= 0.0 && b >= 0.0)
                printf("Y %.9lf %.9lf\n", a, b);
            else
                printf("N\n");
        }
    }
}