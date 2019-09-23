#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll n;
bool space = false;
void printR(ll prev, ll curr) {
    ll tcurr = n / curr;
    ll tprev = n / prev;
    for(int i = 0; i < (tprev - tcurr); i++) {
        if(space) cout << " ";
        cout << prev;
        space=true;
    }
    if(curr <= n) printR(curr, curr * 2LL);
}


int main(void) {
    cin >> n;
    if(n == 3) {
        printf("1 1 3");
    } else printR(1LL, 2LL);
    cout << endl;
}