#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXS = 1000000010;

int n, l, r, x, problem[16];
unsigned short subset[MAXS];
bool dp[MAXS];
long long ans = 0;

bool check(int val) {
    if(val < l || val > r) return false;
    int ez = INT_MAX - 10, hardest = 0, chosen = 0;

    for(int i = 0; i < n; i++)
        if(subset[val] & (1 << i)) {
            chosen++;
            ez = min(ez, problem[i]);
            hardest = max(hardest, problem[i]);
        }
    if(hardest - ez >= x && chosen > 1) return true;
    return false;
}

void knap() {
    for(int i = 0; i < n; i++) for(int j = r; j >= 0; j--) {
        if(dp[j] && problem[i] + j <= r) {
            dp[j + problem[i]] = true;
            subset[j + problem[i]] = (subset[j] |= (1 << i));
            if(check(j + problem[i])) ans++;
        }
    }
}

int main() {
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++)
        cin >> problem[i];
    memset(dp, false, sizeof(dp));
    memset(subset, 0, sizeof(subset));
    dp[0] = true;
    knap();
    cout << ans << endl;
}