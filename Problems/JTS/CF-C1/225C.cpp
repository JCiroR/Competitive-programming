#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
int b[MAXN];

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    ll ans = 0, count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(b[i] == 0) count++;
        else ans += count;
    }
    cout << ans << endl;
}
