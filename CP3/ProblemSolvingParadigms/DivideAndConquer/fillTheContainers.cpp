#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1005;
int vess[MAXN];

bool simulate(int maxCap, int n, int m) {
    int used = 1, curr = 0;
    for(int i = 0; i < n; i++) {
        if(vess[i] > maxCap) return false;
        if(curr + vess[i] <= maxCap) curr += vess[i];
        else {
            used++;
            curr = vess[i];
            if(used > m) return false;
        } 
    }
    return used <= m;
}


int main(void) {
    int n, m;
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++)
            scanf("%i", &vess[i]);
        
        int low = 0, hi = 1000 * 1000000, mid;
        while(low < hi) {
            if(low + 1 == hi) {
                if(simulate(low, n, m)) mid = low;
                else mid = hi; 
                break;
            }
            mid = (low + hi)/2;
            if(simulate(mid, n, m)) hi = mid;
            else low = mid;
        }
        printf("%i\n", mid);
    }
}