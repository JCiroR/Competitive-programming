#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e4 + 20;
int n, p[N];
bool seen[N];

int findCycle(int i) {
    if(seen[i]) return i;
    else seen[i] = true;
    return findCycle(p[i]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++) {
        if(i > 1) cout  << " ";
        memset(seen, false, sizeof(seen));
        cout << findCycle(i);
    }
    cout << endl;
}