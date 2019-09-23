#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

const int maxn = 1e5 * 3 + 10;
array<long long, maxn> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);
    long long ans = 0;
    for(long long i = 0; i < n; i++)
    {
        ans += a[i] * (i + 2LL);
    }
    ans -= a[n-1];
    cout << ans << endl;
}