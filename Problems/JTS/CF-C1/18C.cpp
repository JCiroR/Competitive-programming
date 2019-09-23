// That escalated quickly

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
string s;
bool goes[maxn], goes2[maxn];

deque<int> one, two;


int main() {
    memset(goes, true, sizeof(goes));
    memset(goes2, true, sizeof(goes2));
    cin >> s;
    ll sum = 0;
    int n = s.size();
    bool zero = false;
    for(int i = 0; i < n; i++) {        
        int dig = s[i] - '0';
        if(dig == 0) zero = true;
        if(dig % 3 == 1) one.push_front(i);
        if(dig % 3 == 2) two.push_front(i);
        if(one.size() > 2) one.pop_back();
        if(two.size() > 2) two.pop_back();
        sum += dig;
    }
    bool goes1 = true;
    if(sum % 3 == 0) { cout << s << endl; return 0;}
    else if(sum % 3 == 1) {
        if(one.size() == 0 && two.size() < 2) { cout << -1 << endl; return 0;}
        int cost = INT_MAX;
        if(one.size() > 0) {
            cost = 1;
            int bestI = one.front();
            goes[bestI] = false;
            if(bestI == 0) {
                for(int i = 1; i < n-1; i++) {
                    if(s[i] != '0') break;
                    goes[i] = false;
                    cost++;
                }
            }
        }
        if(two.size() == 2) {
            int b1 = two.front(); two.pop_front();
            int b2 = two.front(); two.pop_front();
            int cost2 = 2;
            goes2[b1] = goes2[b2] = false;
            if(b2 == 0) {
                for(int i = 1; i < n; i++) {
                    if(s[i] != '0') break;
                    goes2[i] = false;
                    cost2++;
                }
                if(goes2[b1-1] == false) {
                    for(int i = b1+1; i < n; i++) {
                        if(s[i] != '0') break;
                        goes2[i] = false;
                        cost2++;
                    }
                }
            }
            if(cost2 < cost) goes1 = false;
        }
    } else {
        if(one.size() == 0 && two.size() == 0) { cout << -1 << endl; return 0;}
        int cost = INT_MAX;
        if(two.size() > 0) {
            int two_ind = two.front();
            cost = 0;
            goes[two_ind] = false;
            cost++;
            if(two_ind == 0) {
                for(int i = 1; i < n-1; i++) {
                    if(s[i] != '0') break;
                    goes[i] = false;
                    cost++;
                }
            }
        }
        if(one.size() == 2) {
            int b1 = one.front(); one.pop_front();
            int b2 = one.front(); one.pop_front();
            int cost2 = 2;
            goes2[b1] = goes2[b2] = false;
            if(b2 == 0) {
                    for(int i = 1; i < n; i++) {
                        if(s[i] != '0') break;
                        goes2[i] = false;
                        cost2++;
                    }
                    if(goes2[b1-1] == false) {
                        for(int i = b1+1; i < n; i++) {
                            if(s[i] != '0') break;
                            goes2[i] = false;
                            cost2++;
                        }
                    }
            }
            if(cost2 < cost) goes1 = false;
        }
    }
    bool print = false;
    if(goes1) {
        for(int i = 0; i < n; i++) 
            if(goes[i]) {
                print = true;
                cout << s[i];
            }
    } else {
         for(int i = 0; i < n; i++) 
            if(goes2[i]) {
                print = true;
                cout << s[i];
            }
    }
    if(print) cout << endl;
    else {
        if(zero) cout << 0 << endl;
        else cout << -1 << endl;
    }
}