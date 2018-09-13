#include <cstdio>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

const int MAXN = 210;
const int MAXM = 11;
const int MAXS = 22;

int n, q, m, d, numb[MAXN];
ll dp[MAXN][MAXM][MAXS];

ll func(int index, int taken, int sum) {

    if(taken == m) {
        if(sum == 0) return 1;
        else return 0;
    } else if(index >= n) return 0;

    ll mem = dp[index][taken][sum]; 
    if(mem != -1) return mem;

    ll temp = numb[index] + sum;
    temp %= d;
    if(temp < 0) temp += d;
    
    ll ifTaken = func(index + 1, taken + 1, temp);
    ll noTaken = func(index + 1, taken, (sum) % d);

    dp[index][taken][sum] = ifTaken + noTaken;
    return ifTaken + noTaken;
}

int main(void) {
    int set = 0;
    while(scanf("%d %d",&n, &q) == 2 && (n && q)) {
        set++;
        printf("SET %d:\n", set);
        for(int i = 0; i < n; i++) scanf("%d", &numb[i]);

        for(int i = 0; i < q; i++) {
            scanf("%d %d", &d, &m);
            memset(dp, -1, sizeof(dp));
            printf("QUERY %d: %lld\n",i+1, func(0,0,0));
        }
    }
    return 0;
}