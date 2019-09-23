#include <bits/stdc++.h>
using namespace std;

bool nline = false;

namespace suffix {
    const int N = 1e3;
    string s;
    int n;
    int ra[N], tra[N];
    int sa[N], tsa[N];
    int lcp[N];
    int c[N];
    void counting_sort(int k) {
        int sum, maxi = max(300, n);
        memset(c, 0, sizeof c);
        for(int i = 0; i < n; i++)
            c[i + k < n ? ra[i + k] : 0]++;
        for(int i = sum = 0; i < maxi; i++) {
            int t = c[i]; c[i] = sum; sum += t;
        }
        for(int i = 0; i < n; i++)
            tsa[c[sa[i] + k < n? ra[sa[i]+k] : 0]++] = sa[i];
        for(int i = 0; i < n; i++)
            sa[i] = tsa[i];
    }
    void build_sa() {
        n = s.size();
        int r;
        for(int i = 0; i < n; i++) ra[i] = s[i];
        for(int i = 0; i < n; i++) sa[i] = i;
        for(int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            tra[sa[0]] = r = 0;
            for(int i = 1; i < n; i++)
                tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && 
                                ra[sa[i]+k] == ra[sa[i-1] + k]) ? r: ++r;
            for(int i = 0; i < n; i++)                                
                ra[i] = tra[i];
            if(ra[sa[n-1]] == n - 1) break;
        }
    }

    void build_lcp() {
        int l = 0;
        lcp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i == sa[0]) continue;
            while(s[i + l] == s[sa[ra[i]-1] + l]) l++;
            lcp[ra[i]] = l;
            l = max(l - 1, 0);
        }
    }


    vector<int> sepIndices;
    int owner(int sIndex) {
        if(sepIndices.empty()) cout << "Load sepIndices!!" << endl;
        for(int i = 0; i < sepIndices.size(); i++)
            if(sIndex <= sepIndices[i]) return i;
        return -1;
    }

    void solve() {
        int longest = 0;

        for(int i = 1; i < n; i++) {
            if(owner(sa[i]) != owner(sa[i-1])) {
                longest = max(longest, lcp[i]);
            }
        }
        if(nline) cout << "\n";
        else nline = true;
        if(longest != 0) {
            set<string> ans;
            for(int i = 1; i < n; i++) {
                if(lcp[i] == longest && owner(sa[i]) != owner(sa[i-1])) {
                    int idx = max(sa[i], sa[i-1]);
                    ans.insert(s.substr(idx, longest));
                }
            }
            for(auto it = ans.begin(); it != ans.end(); ++it) {
                cout << *it << endl;
            }
        } else {
            cout << "No common sequence." << endl;
        }
    }
}

int main() {
    string s1, s2, trash, s;
    s1.reserve(310);
    s2.reserve(310);
    s.reserve(700);
    while(cin >> s1 >> s2) {
        s = s1 + "#" + s2 + "$";
        suffix::sepIndices.push_back(s1.size());
        suffix::sepIndices.push_back(s1.size() + 1 + s2.size());
        suffix::s = s;
        suffix::build_sa();
        suffix::build_lcp();
        suffix::solve();
    }
}