#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int n, m, x, y, dp[MAXN][MAXN][2], white[MAXN];

int func(int index, int taken, int col) {
   if(index >= m) {
       if(taken >= x && taken <= y) return 0;
       else return 10000 * 10000;
   }
   if(dp[index][taken][col] != -1) return dp[index][taken][col];
   int ans = 10000 * 10000;
   if(taken == 0) {
       ans = min(ans, white[index] +  func(index + 1, 1, 1));
       ans = min(ans, n - white[index] +  func(index + 1, 1, 0));
   } else if(taken >= x) {
       if(col == 0) ans = min(ans, white[index] + func(index + 1, 1, 1));
       else ans = min(ans, n - white[index] + func(index + 1, 1, 0));
       if(taken < y) {
           if(col == 0) ans = min(ans, n - white[index] + func(index + 1, taken + 1, 0));
           else ans = min(ans, white[index] + func(index + 1, taken + 1, 1));
       }
   } else if(taken < x) {
       if(col == 0) ans = min(ans, n - white[index] + func(index + 1, taken + 1, 0));
       else ans = min(ans, white[index] + func(index + 1, taken + 1, 1));
   }
   return dp[index][taken][col] = ans; 
}


int main() {
    memset(white, 0, sizeof(white));
    for(int i = 0; i < MAXN; i++) 
        for(int j = 0; j < MAXN; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    cin >> n >> m >> x >> y;
    char temp;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            cin >> temp;
            if(temp == '.') white[j]++;
        }
    cout << func(0, 0, 1) << endl;
}