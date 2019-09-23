#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;
point rec1[5], rec2[5];

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double x5, y5, x6, y6, x7, y7, x8, y8;
    while(scanf("%lf %lf\n%lf %lf\n%lf %lf\n%lf %lf\n",
           &x1,&y1, &x2,&y2, &x3,&y3,  &x4,&y4) == 8 && 
    scanf("%lf %lf\n%lf %lf\n%lf %lf\n%lf %lf\n",
            &x5, &y5, &x6, &y6, &x7, &y7, &x8, &y8) == 8) {
    rec1[0] = point(x1, y1);
    rec1[1] = point(x2, y2);
    rec1[2] = point(x3, y3);
    rec1[3] = point(x4, y4);
    
    rec2[0] = point(x5, y5);
    rec2[1] = point(x6, y6);
    rec2[2] = point(x7, y7);
    rec2[3] = point(x8, y8);
    bool equal = true;
    for(int i = 0; i < 4; i++) {
        bool curr = false;
        for(int j = 0; j < 4; j++) {
            if(rec1[i] == rec2[j]) curr = true;
        }
        if(!curr) {
            equal = false;
            break;
        }
    }
    if(equal) {
        printf("NO\n");
    } else {
        double p1x, p1y, p2x, p2y;
        p1x = (x1 + x2 + x3 + x4)/4.0;
        p1y = (y1 + y2 + y3 + y4)/4.0;
        p2x = (x5 + x6 + x7 + x8)/4.0;
        p2y = (y5 + y6 + y7 + y8)/4.0;
        if(p1x == p2x && p1y == p2y) {
            p2x = x7;
            p2y = y7;
        }

        printf("YES %.5lf %.5lf %.5lf %.5lf\n", p1x, p1y, p2x, p2y);
    }
            }
}