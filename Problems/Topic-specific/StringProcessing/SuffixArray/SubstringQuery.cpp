#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > ii;
typedef long long ll;

namespace suffix {
    const int N = 1e5 + 10;
    string s;
    int n;
    int ra[N], tra[N];
    int sa[N], tsa[N];
    int c[N];
    void counting_sort(int k) {
        int sum, maxi = max(300, n);
        memset(c, 0 , sizeof c);
        for(int i = 0; i < n; i++)
            c[i + k < n? ra[i+k] : 0]++;
        for(int i = sum = 0; i < maxi; i++) {
            int t = c[i]; c[i] = sum; sum += t;
        }
        for(int i = 0; i < n; i++)
            tsa[c[sa[i]+k < n? ra[sa[i] + k]: 0]++] = sa[i];
        for(int i = 0; i < n; i++)
            sa[i] = tsa[i];
    }

    void build_sa() {
        n = s.size();
        int r;
        for(int i = 0; i < n; i++) ra[i] = s[i];
        for(int i = 0; i < n; i++)  sa[i] = i;
        for(int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            tra[sa[0]] = r[0];
            for(int i = 1; i < n; i++)
                tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] &&
                                ra[sa[i]+k] == ra[sa[i-1]+k])? r: ++r;
            for(int i = 0; i < n;i++)
                ra[i] = tra[i];
            if(ra[sa[n-1]] == n-1) break;
        }
    }

    int lcp[N];
    void build_lcp() {
        int l = 0;
        lcp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i == sa[0]) continue;
            while(s[i + l] == s[sa[ra[i]-1] + l]) l++;
            lcp[ra[i]] = l;
            l = max(l-1, 0);
        }
    }

    vector<int> sepIndices;
    int owner(int sIndex) {
        for(int i = 0; i < sepIndices.size(); i++)
            if(sIndex <= sepIndices[i]) return i;
        return -1;
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int k; cin >> k;
        string s, t;
        s.reserve(1e5 + 30);
        t.reserve(1e4 +20);
        for(int i = 0; i < k; i++) {
            cin >> t;
            s += t + "$";
            suffix::sepIndices.push_back(s.size() - 1);
        }
        suffix::build_sa();
        suffix::build_lcp();
    }
}