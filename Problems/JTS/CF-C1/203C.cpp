#include <utility>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> bomb;
const int MAXN = 1e5 + 10;
bomb v[MAXN];

int main() {
    int n; scanf("%d", &n);
    int k = 2*n;
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x,&y);
        v[i] = bomb(abs(x) + abs(y), ii(x, y));
        if(x != 0) k += 2;
        if(y != 0) k += 2;
    }
    sort(v, v + n);
    printf("%d\n", k);
    for(int i = 0; i < n; i++) {
        ii c = ii(0, 0), t = v[i].second;
        int times;
        while(c != t) {        
            char op;
            if(c.first > t.first) {
                times = c.first - t.first;
                op =  'L';
                c.first = t.first;
            } else if(c.first < t.first) {
                times = t.first - c.first;
                op =  'R';
                c.first = t.first;
            } else if(c.second > t.second) {
                times = c.second - t.second;
                op =  'D';
                c.second = t.second;
            } else if(c.second < t.second) {
                times = t.second - c.second;
                op =  'U';
                c.second = t.second;
            }
            printf("1 %d %c\n", abs(times), op);
        }
        printf("2\n");
        c = v[i].second, t = ii(0, 0);
        while(c != t) {        
            char op;
            if(c.first > t.first) {
                times = c.first - t.first;
                op =  'L';
                c.first = t.first;
            } else if(c.first < t.first) {
                times = t.first - c.first;
                op =  'R';
                c.first = t.first;
            } else if(c.second > t.second) {
                times = c.second - t.second;
                op =  'D';
                c.second = t.second;
            } else if(c.second < t.second) {
                times = t.second - c.second;
                op =  'U';
                c.second = t.second;
            }
            printf("1 %d %c\n", abs(times), op);
        }
        printf("3\n");
    }
}