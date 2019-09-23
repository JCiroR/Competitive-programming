//https://www.spoj.com/problems/BSHEEP/
#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    int id;
};

bool cmp(pt a, pt b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    sort(a.begin(), a.end(), &cmp);

    pt p1 = a[0], p2 = a.back();
    vector<pt> r, l;
    r.push_back(p1);
    l.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++) {
        if(i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(r.size() >= 2 && !ccw(r[r.size()-2], r[r.size() - 1], a[i]))
                r.pop_back();
            r.push_back(a[i]);
        }
        if(i == a.size() - 1 || cw(p1, a[i], p2)) {
            while(l.size() >= 2 && !ccw(l[l.size()-2], l[l.size() - 1], a[i]))
                l.pop_back();
            l.push_back(a[i]);
        }
    }

    a.clear();
    for(int i = 0; i < (int)r.size(); i++)
        a.push_back(r[i]);
    for(int i = l.size() - 2; i > 0; i--)
        a.push_back(l[i]);
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {

        
        
        
        
        if(t) printf("\n");
    }    
}