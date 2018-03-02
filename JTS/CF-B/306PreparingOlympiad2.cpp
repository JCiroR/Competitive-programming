#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

long long ans = 0;
int n, l, r, x, prob[16];

int main() {
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++) cin >> prob[i];
    int start = (1 << n) - 1;
    while(start > 0) {
        int sum = 0, count = 0, ez = INT_MAX, hardest = 0;
        for(int i = 0; i < n; i++)
            if(start & (1 << i)) {
                sum += prob[i];
                count++;
                ez = min(ez, prob[i]);
                hardest = max(hardest, prob[i]);
            
            }
        if(sum >= l && sum <= r && count >= 2 && hardest - ez >= x)
            ans++;    
        start--;
    }
    cout << ans << endl;
}