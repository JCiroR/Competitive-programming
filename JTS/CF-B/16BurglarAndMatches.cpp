#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> li;

vector<li> cont;

bool comp(li a, li b) {
    return a.second > b.second;
}

int main(void) {
    ll n, boxes;
    int m, matches;
    cin >> n >> m;
    cont.clear();
    for(int i = 0; i < m; i++) {
        cin >> boxes >> matches;
        cont.push_back(make_pair(boxes, matches));
    }
    sort(cont.begin(), cont.end(), comp);
    ll ans = 0;
    for(int i = 0; i < m && n > 0; i++) {
        if(n > cont[i].first) {
            n -= cont[i].first;
            ans += cont[i].first * cont[i].second;
        } else {
            ans += cont[i].second * n;
            n = 0;
        }
    }
    cout << ans << endl;
}