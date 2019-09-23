#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int dp[101][4], day[101], n;

int restDays(int index, int prev) {
    if(index >= n) return 0;
    if(dp[index][prev] != -1) return dp[index][prev];

    int ans = n, today = day[index];
    if((today & 1) && prev != 1) ans = min(ans, restDays(index + 1, 1));
    if((today & 2) && prev != 2) ans = min(ans, restDays(index + 1, 2));
    ans = min(ans, 1 + restDays(index + 1, 0));
    return dp[index][prev] = ans;
}

int main() {
    for(int i = 0; i <= 100; i++) for(int j = 0; j < 4; j++) dp[i][j] = -1;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> day[i];
    cout << restDays(0, 0) << endl;
}