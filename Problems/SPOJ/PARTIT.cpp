//https://www.spoj.com/problems/PARTIT/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 221, N = 11;
int n, m, k, currK;
bool retrieving;
vector<int> ans;

ll dp[M][N];

bool fun(int _m, int _n, bef) {
    if(_m == 0 && _n == 0) {
        currK++;
        
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        currK = 0;
        retrieving = false;
        ans.clear();
        memset(dp, -1, sizeof(dp));
        fun(m, n, 1);
        for(int i = 0; i < ans.size(); i++) {
            if(i > 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}