#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 3020;

int n, m;
multiset<int> votes;
vector<int> v_party[N];

int main(void) {
    cin >> n >> m;
    int party, cost;
    for(int i = 0; i < n; i++) {
        cin >> party >> cost;
        if(party != 1) votes.insert(cost);
        v_party[party].pb(cost);
    }
    for(int i = 1; i <= m; i++)
        sort(v_party[i].begin(), v_party[i].end(), greater<int>());
    ll ans = 1LL << 50, fixed = 0;        
    int myv = v_party[1].size();
    for(int x = min(1501, n); x >= 1; x--) {
        for(int i = 2; i <= m; i++) {
           while(v_party[i].size() >= x) {
               int price = v_party[i].back();
               v_party[i].pop_back();
               
               myv++;
               fixed += price;
               auto it = votes.find(price);
               if(it != votes.end()) votes.erase(it);
           }
        }
        ll curr = fixed;
        int currv = myv;
        auto it = votes.begin();
        while(currv < x) {
            curr += *it;
            it++;
            currv++;
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
}