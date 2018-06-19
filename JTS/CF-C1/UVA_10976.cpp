#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int k;
    vector<pair<int, int> > ans;
    while(scanf("%d", &k) == 1) {
        ans.clear();
        int count = 0;
        for(int x = k + 1; x <= 2 * k; x++) {
            if((k * x) % (x - k) == 0) {
                count++;
                ans.push_back(make_pair( (k * x)/(x - k), x));
            }
        }
        printf("%d\n", count);
        for(int i = 0; i < ans.size(); i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, ans[i].first, ans[i].second);
        }
    }
}