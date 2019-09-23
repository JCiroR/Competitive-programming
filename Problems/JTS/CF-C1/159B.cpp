#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p = 0, v = 0;
char a = 'A', b = 'B';

void sim(string s, ll n, ll m, bool second) {
    ll p1 = 0, v1 = 0;
    bool firstP = false;
    while(n || m) {
        if(firstP) {
            firstP = false;
            if(s[s.size()-1] == 'A') {
                if(n > 0) n--, p1++, s.push_back(a);
                else m--, v1++, s.push_back(b);
            }
            else {
                if(m > 0) m--, p1++, s.push_back(b);
                else n--, v1++, s.push_back(a);
            }
        } else {
            firstP = true;
            if(s[s.size()-1] == 'A') {
                if(m > 0) m--, v1++, s.push_back(b);
                else n--, p1++, s.push_back(a);
            }
            else {
                if(n > 0) n--, v1++, s.push_back(a);
                else m--, p1++, s.push_back(b);
            }
        }
    }
    if(second) {
        if(p1 > p) p = p1, v = v1;
        else if(p1 == p) v = min(v, v1);
    } else p = p1, v = v1;
}
int main() {
    ll n, m;
    cin >> n >> m;
    string s = "";
    s.push_back(a);
    sim(s, n-1, m, false);
    
    s.clear();
    s.push_back(b);
    sim(s, n, m-1, true);

    cout << p << " " << v << endl;
}