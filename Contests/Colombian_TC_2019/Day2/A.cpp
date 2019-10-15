#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int N = 1010;
const ll INF = 1LL << 32;
ll n;
ll dp[N][N][3];
ll mat[N][N][3];
char ans[N];
int ans_sz = 0;

void print_path_i(int i) {
    for(int r = 0, c = 0; r + 1 < n || c + 1 < n;) {
        if(r + 1 < n && c + 1 < n) {
            if(dp[r + 1][c][i] < dp[r][c + 1][i]) {
                ans[ans_sz++] = 'D';
                r++;
            } else {
                ans[ans_sz++] = 'R';
                c++;
            }
        } else if(r + 1 < n) {
            ans[ans_sz++] = 'D';
            r++;
        } else {
            ans[ans_sz++] = 'R';
            c++;
        }
    }
    ans[ans_sz] = '\0';
    printf("%s", ans);
}

void fill_dp() {
    for(int i = 0; i < 3; i++) {
        for(int r = n - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--) {
                dp[r][c][i] = mat[r][c][i];
                if(r + 1 < n && c + 1 < n)
                    dp[r][c][i] += min(dp[r + 1][c][i], dp[r][c + 1][i]);
                else if(c + 1 < n)
                    dp[r][c][i] += dp[r][c + 1][i];
                else if(r + 1 < n)
                    dp[r][c][i] += dp[r + 1][c][i];
            }
        }
    }
}

int main() {
    cin >> n;
    memset(mat, 0, sizeof(mat));
    memset(dp, 0, sizeof(dp));
    bool has_zeroes = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp; scanf("%d", &temp);
            if(temp == 0) {
                mat[i][j][2] = -1;
                has_zeroes = true;
                continue;
            }
            while(temp % 2 == 0) temp /= 2, mat[i][j][0]++;
            while(temp % 5 == 0) temp /= 5, mat[i][j][1]++;
        }
    }
    fill_dp();

    if(has_zeroes && 1 < min(dp[0][0][0], dp[0][0][1])) {
        cout << 1 << endl;
        print_path_i(2);
    } else if(dp[0][0][0] < dp[0][0][1]) {
        cout << dp[0][0][0] << endl;
        print_path_i(0);
    } else {
        cout << dp[0][0][1] << endl;
        print_path_i(1);
    }
}
