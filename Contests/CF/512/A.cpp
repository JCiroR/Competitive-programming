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
    int n; cin >> n;
    bool ans = 0;
    int temp;
    while(n--) {
        cin >> temp;
        ans |= temp;
    }
    if(ans) cout << "HARD" << endl;
    else cout << "EASY"  << endl;
}