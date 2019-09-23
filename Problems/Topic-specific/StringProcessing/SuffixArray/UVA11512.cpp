#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int > ii;

namespace suffix {
    const int N = 1e3 + 20;
    string s;
    int n; 
    int ra[N], tra[N];
    int sa[N], tsa[N];
    int c[N];

    void counting_sort (int k) {
        int sum, maxi = max(300, n);
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; i++)
            c[i + k < n ? ra[i + k] : 0]++;
        for (int i = sum = 0; i < maxi; i++) {
            int t = c[i]; c[i] = sum; sum += t; 
        }
        for (int i = 0; i < n; i++) // shuffle the suffix array if necessary
            tsa[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
        for (int i = 0; i < n; i++)
            sa[i] = tsa[i];
    }

    void build_sa () {
        n = s.size();
        int r;
        for (int i = 0; i < n; i++) ra[i] = s[i];
        for (int i = 0; i < n; i++) sa[i] = i;
        for (int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            tra[sa[0]] = r = 0; //Re-ranking
            for (int i = 1; i < n; i++)
                tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] &&
                              ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;
            for (int i = 0; i < n; i++)
                ra[i] = tra[i];            //Update rankings
            if (ra[sa[n-1]] == n-1) break; //Every ranking has ben used
        }
    }

    int lcp[N];
    //lcp[i] means the maximum common prefix of sa[i] and sa[i - 1]
    void build_lcp(){
        int l = 0;
        lcp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i == sa[0]) continue;
            while(s[i + l] == s[sa[ ra[i]-1] + l]) l++;
            lcp[ ra[i] ] = l;
            l = max(l-1, 0);
        }
    }

    string p;
    ii stringMatching() {
        int m = p.size();
        int lo = 0, hi = n - 1, mid = lo;
        while(lo < hi) {
            mid = (lo + hi) / 2;
            int res = s.compare(sa[mid], m, p);
            if(res >= 0) hi = mid;
            else lo = mid + 1;
        }
        if(s.compare(sa[lo], m, p) != 0) return ii(-1, -1);
        ii ans; ans.first = lo;
        lo = 0; hi = n - 1; mid = lo;
        while(lo < hi) {
            mid = (lo + hi) / 2;
            int res = s.compare(sa[mid], m, p);
            if(res > 0) hi = mid;
            else  lo = mid + 1;
        }
        if(s.compare(sa[hi], m, p) != 0) hi--;
        ans.second = hi;
        return ans;
    }

    void solve() {
        int idx, size = 0;
        for(int i = 1; i < n; i++)
            if(lcp[i] > size) {
                size = lcp[i];
                idx = sa[i];
            }
        if(size == 0)
            cout << "No repetitions found!\n";
        else {
            p.clear();
            p.reserve(size);
            for(int i = 0; i < size; i++)
                p += s[idx + i];
            ii ans = stringMatching();
            cout << p << " " << ans.second - ans.first + 1  << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    string s;
    s.reserve(1010);
    while (T--)
    {
        cin >> s;
        s += "$";
        suffix::s = s;
        suffix::build_sa();
        suffix::build_lcp();
        suffix::solve();
    }
}