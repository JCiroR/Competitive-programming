#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int M = 1e6 + 10, N = 2e5 + 10;
int a[N], n;
int present[M];
bool mult[M];

int main(void) {
    scanf("%d", &n);
    memset(present, -1, sizeof(present));
    memset(mult, false, sizeof(false));
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
        if(present[a[i]] == -1) {
            present[a[i]] = i;
        }
        else mult[a[i]] == true;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        ll newSum = tot - a[i];
        if(newSum % 2 == 0) {
            ll targ = newSum / 2;
            if(targ >= M) continue;
            if((present[targ] != -1 && present[targ] != i) || mult[targ])
                ans.push_back(i+1);
        }
    }
    printf("%lu\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        if(i > 0) printf(" ");
        printf("%d", ans[i]);
    }   
   if(ans.size() != 0) printf("\n");
}