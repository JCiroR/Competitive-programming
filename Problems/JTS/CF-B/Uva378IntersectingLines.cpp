#include <iostream>
#include <utility>
#include <cmath>
#include <cstdio>

#define EPS 1e-9

using namespace std;

struct line { double a, b, c; };

struct point {
    double x, y;
    point() { x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y){};
};

void pointsToLine(point p1, point p2, line &l) {
    if(fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -double(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool areSame(line l1, line l2) {
    return areParallel(l1,l2) && fabs(l1.c - l2.c) < EPS;
}

bool areIntersect(line l1, line l2, point &p) {
    if(areParallel(l1,l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                 p.y = -(l2.a * p.x + l2.c);
    return true;
}

int main() {
    int n; cin >> n;
    printf("INTERSECTING LINES OUTPUT\n");
    point p1, p2 ,p3 ,p4, p5;
    line l1, l2;
    while(n--) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        pointsToLine(p1, p2, l1);
        pointsToLine(p3, p4, l2);
        //cout << l1.a << " " << l1.b << " " << l1.c << endl;
        //cout << l2.a << " " << l2.b << " " << l2.c << endl;
        if(areSame(l1, l2)) printf("LINE\n");
        else if(areParallel(l1, l2)) printf("NONE\n");
        else {
            areIntersect(l1, l2, p5);
            printf("POINT %.2f %.2f\n", p5.x, p5.y);
        }        
    }
    printf("END OF OUTPUT\n");
}