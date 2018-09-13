// http://codeforces.com/problemset/problem/799/D
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int a,b,h,w,n, arr[N], ans = 50;
int dp[36][N] = {0};

int main() {
    scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n, greater<int>());
    int an = n;
    n = min(34, n);
    if(a > b) swap(a, b);
    if(min(w,h) >= a && max(w, h) >= b) {
        printf("0\n");
        return 0;
    }
    dp[0][w] = h;
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j < N; j++) {
            int &aux = dp[i-1][j];
            if(aux == 0) continue;
            if(min(j, aux) >= a && max(j, aux) >= b) {
                printf("%d\n", i - 1);
                return 0;
            }
            if(!(i <= n)) continue;
            int id = min((ll)j * arr[i-1], (ll)N-2);
            dp[i][j] = max((ll)dp[i][j], min((ll)aux*arr[i-1], (ll)N-2));
            dp[i][id] = max(aux, dp[i][id]);
        }
    }
   printf("-1\n");
}