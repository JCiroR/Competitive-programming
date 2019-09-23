#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(void) {
    int L, v, l, r;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &L, &v, &l, &r);
        int ans = L/v - r/v + (l-1)/v;
        printf("%d\n", ans);
    }

}