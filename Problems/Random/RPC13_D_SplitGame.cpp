#include <bits/stdc++.h>
using namespace std;
const int N = 2001;

int dp[N];

int fun(int u) {
    if(u < 2) return dp[u] = 0;
    if(dp[u] != -1) return dp[u];

    int mex = 0;
    set<int> mexAux;
    for(int k = 1; k < u; k++) {
        if(u%k == 0 && ((u/k)&1))
            mexAux.insert(fun(k));
        if(u%k != 0) {
            mexAux.insert(fun(u%k));
            if((u/k)&1) mexAux.insert(fun(k));
        }
    }
    while(mexAux.count(mex)) mex++;
    return dp[u] = mex;
}

int main () {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= 2000; i++)
        if(dp[i] == -1) fun(i);
    int n; cin >> n;
    int xorSum = 0;
    for(int i = 0; i < n; i++) {
        int pile; cin >> pile;
        xorSum ^= dp[pile];
    }
    cout << (xorSum?"First":"Second") << endl;
}