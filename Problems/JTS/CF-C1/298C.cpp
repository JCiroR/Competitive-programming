#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 20;
ll a[MAXN];

int main() {
    ll n, S; cin >> n >> S;
    ll maxSum = 0, minSum = n - 1, temp;
    for(int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        maxSum += a[i];
    }
    for(int i = 0; i < n; i++) {        
        ll minCont = max(1LL, S - (maxSum - a[i]));
        ll maxCont = min(a[i], (S - minSum));
        maxCont = a[i] - maxCont;
        if(i > 0) printf(" ");
        printf("%I64d", maxCont + minCont - 1LL);
    }
    printf("\n");
}