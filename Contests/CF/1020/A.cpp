#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, h, a, b, k, ta, fa, tb, fb;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> h >> a >> b >> k;
    while(k--) {
        cin >> ta >> fa >> tb >> fb;
        ll dist = 0, pos = fa;
        if(ta != tb) {
            if(fa > b) {
                dist += (fa - b);
                pos = b;
            } else if(fa < a) {
                dist += a - fa;
                pos = a;
            }
            dist += abs(ta - tb);
        }
        dist += abs(fb - pos);
        cout << dist << endl;
    }
}