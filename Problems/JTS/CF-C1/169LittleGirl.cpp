#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN = 100010*2;
int nums[MAXN], ans[MAXN], n, q, li, ri, a;
pii freq[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        freq[i] = make_pair(0, i);
        cin >> nums[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> li >> ri;
        li--; ri--;
        freq[li].first++;
        if(ri + 1 < n) freq[ri + 1].first--;
    }
    ll acum = 0;
    for(int i = 0; i < n; i++) {
        acum += freq[i].first;
        freq[i].first = acum;
    }
    sort(freq, freq + n);
    sort(nums, nums + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += ll(freq[i].first) * ll(nums[i]);
    }
    cout << ans << endl;
}