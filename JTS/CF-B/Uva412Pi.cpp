#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 51;

int nums[MAXN];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(void) {
    int n;
    while(cin >> n && n) {
        for(int i = 0; i < n; i++) cin >> nums[i];
        int noCommon = 0, pairs = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                if(gcd(nums[i], nums[j]) == 1) noCommon++;    
                pairs++;
            }
        if(noCommon) {
            double ans = 6 * pairs;
            ans /= noCommon;
            ans = sqrt(ans);
            printf("%.6f\n", ans);
        } else printf("No estimate for this data set.\n");
    }
}