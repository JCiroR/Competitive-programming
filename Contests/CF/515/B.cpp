#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int a[1010];

int n, r;

bool inRange(int i, int h) {
    return i >= (h - r + 1) && i <= h + r - 1;
}

int main(void) {
    scanf("%d %d", &n, &r);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0;
    int h = 0, prev = 0;
    for(int i = 0; i < n; i++) {
        bool found = false;
        while(h < n) {
            if(a[h] == 0) {
                h++;
                continue;
            }
            
            if(inRange(i, h)) {
                found = true;
                prev = h;
            }
            else break;
            h++;
        }
        if(!found) { 
            cout << -1 << endl; 
            return 0;
        } 
        ans++;
        i = prev + r - 1;
    }
    cout << ans << endl;
}