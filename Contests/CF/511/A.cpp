#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c, n;
    cin >> n;
    if(n % 3 == 0) {
        a = 1, b = 1, c = n - 2;
    } else {
        a = 1, b = 2, c = n - 3;
    }
    cout  << a << " " << b << " " << c << endl;
}