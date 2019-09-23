#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, t; cin >> n >> x;
    bool pres = false;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        if(t == x) pres = true;
    }
    int op = 0;
    if(!pres) {
        a.push_back(x);
        op++;
        n++;
    }
    sort(a.begin(), a.end());
    int med_i = ((n+1)/2) - 1, med = a[med_i];    
    if(x == med) cout << op << endl;
    else {
        int diff;
        if(x > med)
            for(int i = med_i; i < a.size(); i++)
                if(a[i] == x) {
                    diff = i - med_i;
                    break;
                }                            
        if(x < med)
            for(int i = med_i; i >= 0; i--)
                if(a[i] == x) {
                    diff = med_i - i;
                    break;
                }
        //cout << n << " " << diff << " " << med_i << endl;                        
        op += diff * 2;
        if(x < med && (n&1)) op--;
        if(x > med && n % 2 == 0) op--;
        cout << op << endl;
    }
}