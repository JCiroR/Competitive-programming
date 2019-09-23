#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100010;
int h[MAXN], p[MAXN], dp[MAXN][3], n;

int func(int index, int prevAct) {
    if(index == n) return 1;
    else if(dp[index][prevAct] != -1) return dp[index][prevAct];

    int ans = 0, pos = p[index], height = h[index]; 
    int left = pos - height, right = pos + height;
    
    if(p[index + 1] > right) ans = max(ans, 1 + func(index + 1, 2));
    if((prevAct == 0 || prevAct == 1) && p[index-1] < left) ans = max(ans, 1 + func(index + 1, 1));
    else if(prevAct == 2 && p[index-1] + h[index-1] < left) ans = max(ans, 1 + func(index + 1, 1));
    ans = max(ans, func(index + 1, 0));
    
    return dp[index][prevAct] = ans;
}

int main() {
    cin >> n;
    int xi, hi;
    for(int i = 1; i <= n; i++) {
        cin >> xi >> hi;
        p[i] = xi;
        h[i] = hi;
    }
    for(int i = 0; i < MAXN; i++) for(int j = 0; j < 3; j++) dp[i][j] = -1;
    h[0] = 0;
    p[0] = -1000000001;
    cout << func(1, 0) << endl;  
}