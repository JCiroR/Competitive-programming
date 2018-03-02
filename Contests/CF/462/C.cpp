#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 2005;
int a[MAX], rev[MAX], st[MAX], from[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    st[0] = 1, rev[n-1] = from[n-1] = 1;
    int cMax = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i-1]) st[i] = st[i-1] + 1;
        else st[i] = 1;
        cMax = max(st[i], cMax);
    }
    for(int i = n-2; i >= 0; i--) {
        if(a[i] <= a[i+1]) from[i] = 1 + from[i+1];
        else from[i] = 1;
        if(a[i] >= a[i+1]) rev[i] = rev[i+1] + 1;
        else rev[i] = 1;
        cMax = max(rev[i], cMax);
    }

    for(int i = 0; i < n - 1; i++) { 
        int curr = ((i > 0)? st[i-1]: 0);        
        if(i > 0 && a[i - 1] <= a[i + rev[i] - 1]) {               
            curr += rev[i];                        
            if(i + rev[i] < n && a[i] <= a[i + rev[i]]) curr += from[i + rev[i]];
        } else if(i == 0) {            
            curr += rev[i];
            if(rev[i] < n && a[0] <= a[rev[i]]) curr += from[rev[i]];
        }                                  
        cMax = max(curr, cMax);
    }
    cout << cMax << endl;    
}