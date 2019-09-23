#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <functional>

using namespace std;

typedef pair<double, int> msrm;
int n, t1, t2, k;

bool comp(msrm a, msrm b) {
    if(a.first < b.first) return true;
    else if(b.first < a.first) return false;
    else if(a.second > b.second) return true;
    return false; 
}

double eval(double a, double b, double ck) {
    ck /= 100;
    return a * t1 * (1 - ck) + b * t2;
}

int main() {
    cin >> n >> t1 >> t2 >> k;
    priority_queue<msrm, std::vector<msrm>, std::function<bool(msrm, msrm)> > q(comp);
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        double height = max(eval(a,b,k), eval(b,a, k));
        q.push(make_pair(height, i));
    }
    while(!q.empty()) {
        msrm c = q.top();
        printf("%d %.2f\n", c.second, c.first);
        q.pop();
    }
}