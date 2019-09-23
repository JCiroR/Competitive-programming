#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y; 
    cin >> n >> x >> y;
    int temp, instaKill = 0;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp <= x) instaKill++;
    }
    int ans;
    if(x > y) ans = n;
    else {
        ans = (instaKill >> 1) + (instaKill&1);
    }
    cout << ans << endl;
}