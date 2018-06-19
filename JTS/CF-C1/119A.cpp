#include <bits/stdc++.h>
using namespace std;

int dp[4010], n;
int opt[3];

int solve(int i) {
    if(i == 0) return 0;
    if(i < 0) return -1;
    int * p = &dp[i];
    if(*p != -2) return *p;

    int bT = -1;
    for(int j = 0; j < 3; j++) {
        int t = solve(i - opt[j]);
        if(t >= 0) bT = max(bT, t);
    }

    if(bT >= 0) return *p = 1 + bT;
    else return *p = -1;
}

int main() {
    fill(dp, dp + 4010, -2);
    cin >> n;
    for(int i = 0; i < 3; i++) cin >> opt[i];
    cout << solve(n) << endl;
}