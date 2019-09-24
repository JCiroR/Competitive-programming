#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

namespace suffix {
    const int N = 9e5 + 20;
    string s;
    int n;
    int ra[N], tra[N];
    int sa[N], tsa[N];
    int c[N];
    void counting_sort(int k) {
        int sum, maxi = max(300, n);
        memset(c, 0, sizeof c);
        for(int i = 0; i < n; i++)
            c[i + k < n? ra[i + k] : 0]++;
        for(int i = sum = 0; i < maxi; i++) {
            int t = c[i]; c[i] = sum; sum += t;
        }
        for(int i = 0; i < n; i++)
            tsa[c[sa[i]+k < n? ra[sa[i] +k] : 0]++] = sa[i];
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
                tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i] + k] == ra[sa[i-1]+k]) ? r: ++r;
            for(int i = 0; i < n; i++)
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

    long long prefs[N];

    long long load() {
        memset(prefs, 0, sizeof prefs);
        for(int i = 1; i < n;i++) {
            prefs[i] =  n - sa[i] - lcp[i] - 1 + prefs[i - 1];
        }
        return prefs[n - 1];
    }

    void query(int k) {
     int idx = lower_bound(prefs, prefs + n, k) - prefs;
     if(idx == n) return;
     cout << s.substr(sa[idx], lcp[idx] + k - prefs[idx - 1]) << endl;
    }
}

int main() {
    cin >> suffix::s;
    suffix::s += "$";
    suffix::build_sa();
    suffix::build_lcp();
    long long lim = suffix::load();
    int Q;
    cin >> Q;
    while(Q--) {
        int k;
        cin >> k;
        if(k > lim) continue;
        suffix::query(k);
    }
}
