#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
ll freq[MAXN], n, temp, dp[MAXN];

long long fun(long long num) {
    if(num >= MAXN) return 0;
    if(dp[num] != -1) return dp[num];        
    return (dp[num] = max(fun(num + 1), freq[num] * num + fun(num + 2)));
}


int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++) {
        cin >> temp;
        freq[temp]++;
    }
    cout << fun(0) << endl;
}
