// https://www.codechef.com/problems/ASTRGAME
#include <bits/stdc++.h>
using namespace std;

const int N =  50;
string words[N], s;
int memo[N][N], t, n;
vector<int> startAt[N];

int dp(int l, int r) {
    if(l > r) return 0;
    int & ans = memo[l][r];
    if(ans != -1) return ans;
    
    set<int> mexAux;
    for(int i = l; i <= r; i++) {
        for(int j = 0; j < startAt[i].size(); j++) {
            int w = startAt[i][j];
            if(i + words[w].size() - 1 <= r)
                mexAux.insert(dp(l,i-1)^dp(i + words[w].size(), r));
        }
    }
    ans = 0;
    while(mexAux.count(ans)) ans++;
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        memset(memo,-1, sizeof(memo));
        for(int i = 0; i < N; i++) startAt[i].clear();

        cin >> s;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> words[i];
        for(int i = 0; i < n; i++) {
            size_t pos = 0;
            while(pos < s.size() && pos + words[i].size() <= s.size() && (pos = s.find(words[i], pos)) != string::npos) {
                startAt[pos].push_back(i);
                pos++;
            }
        }
        cout << (dp(0, s.size()-1)? "Teddy":"Tracy") << endl;
    }
}