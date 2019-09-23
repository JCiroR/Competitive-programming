#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    ll ans = 0;
    int x, y;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        ll x_axis;
        x_axis = x + y;
        ans = max(ans, x_axis);
    }
    cout << ans << endl;

}