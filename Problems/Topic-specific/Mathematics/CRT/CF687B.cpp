#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll N = 1e6 + 100;

int isP[N], pCount[N];

int main() {
    isP[0] = isP[1] = 1;
    for(ll i = 2; i < N; i++)
        if(!isP[i])
            for(ll j = i; j < N; j += i)
                isP[j] = i;
    
    ll n, k; 
    scanf("%I64d %I64d", &n, &k);
    for(int i = 0; i < n; i++) {
        ll c; 
        scanf("%I64d", &c);
        while(c != 1) {
            int p = isP[c];
            int cnt = 0;
            while(c % p == 0) {
                cnt++;
                c /= p;
            }
            pCount[p] = max(pCount[p], cnt);
        }
    }
    bool ans = true;
    while(k != 1) {
        int p = isP[k];
        int cnt = 0;
        while(k % p == 0) {
            cnt++, 
            k /= p;
        }
        ans &= (pCount[p] >= cnt);
    }
    ans? printf("Yes\n"): printf("No\n");
}