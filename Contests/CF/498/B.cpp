#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii a[2010];
int n, k;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater< pii >());
    vector<int> ind;
    int ans = 0;
    for(int i = 0; i < k; i++) {
        ans += a[i].first;
        ind.push_back(a[i].second);
    }
    sort(ind.begin(), ind.end());
    cout << ans << endl;
    int last = -1;
    for(int i = 0; i < k; i++) {
        if(i > 0) cout << " ";
        int out = ind[i] - last;
        if(i == k - 1) out += (n - 1) - ind[i];
        cout << out;
        last = ind[i];
    }
    cout << endl;
}