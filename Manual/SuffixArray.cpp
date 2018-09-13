#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
//Only need to initialize s + "$", set N
namespace suffix {
    const int N = 1e5;
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
    //remember to add the '$'
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
}
namespace suffix {
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
}       
namespace suffix {
    //Indices of terminator characters like '$' or '#'
    vector<int> sepIndices;
    int owner(int sIndex) {
        if(sepIndices.empty()) cout << "Load sepIndices!!" << endl;
        for(int i = 0; i < sepIndices.size(); i++)
            if(sIndex <= sepIndices[i]) return i;
        return -1;
    }
    ii LCS() {                 // returns a pair (the LCS length and its index)
        int i, idx = 0, maxLCP = -1;
        for (i = 1; i < n; i++)                         // O(n), start from i = 1
            if (owner(sa[i]) != owner(sa[i-1]) && lcp[i] > maxLCP)
                maxLCP = lcp[i], idx = i;
            return ii(maxLCP, idx);
    }
}

namespace suffix {
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
}

int main() {
    cin >> suffix::s;
    suffix::s += "$";
    suffix::build_sa();
    suffix::build_lcp();
}