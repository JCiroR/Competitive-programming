#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 3 * 1e5 + 10;
int dtime[maxn], n, q;
pii t1[maxn], t2[maxn], t3[maxn];
int bestTPerNot[maxn];

int main() {
    int t1s = 0, t2s = 0, t3s = 0;
    scanf("%d%d", &n, &q);
    memset(dtime, 0, sizeof(dtime));
    memset(bestTPerNot, -1, sizeof(bestTPerNot));
    for(int i = 0; i < q; i++) {
        int op, val;
        scanf("%d%d", &op, &val);
        if(op == 1) {
            t1[t1s].first = val;
            t1[t1s].second = i;
            t1s++;
        }
        else if(op == 2) {
            t2[t2s].first = val;
            t2[t2s].second = i;
            t2s++;
        }
        else {
           if(bestTPerNot[val-1] == -1) bestTPerNot[val-1] = i;
        }
    }
    int bestT = 320200;
    for(int i = t1s; i >= 0; i--) {
        if(bestTPerNot[i] != -1) bestT = min(bestT, bestTPerNot[i]);
        bestTPerNot[i] = bestT;
    }
    sort(t2, t2 + t2s);
    sort(t3, t3+ t3s);
    for(int i = 0; i < t1s; i++) {
        pii p = t1[i];
        dtime[p.second]++;
        int earliest = q + 1;
        pii *  it = upper_bound(t2, t2 + t2s, p);
        if(it != t2 + t2s && (*it).first == p.first && (*it).second >= p.second) {
            earliest = min(earliest, (*it).second);
        }
        earliest = min(earliest, bestTPerNot[i]);
        if(earliest < q) dtime[earliest]--;
    }
    int curr = 0;
    for(int i = 0; i < q; i++) {        
        curr += dtime[i];
        printf("%d\n", curr);
    }
}