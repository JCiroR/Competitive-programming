#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[1010];
ll B, N;

int countWith(ll time) {
    if(time <= 0) return 0;
    ll count = 0;
    for(int i = 0; i < B; i++) {
        count += (time / a[i]) + 1;
    }
    return count;
}

bool isEnough(ll time) {
    ll count = 0;
    for(int i = 0; i < B; i++)
        count += (time / a[i]) + 1;
    return count >= N;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%lld %lld", &B, &N);
        ll minM, maxM;
        for(int i = 0; i < B; i++) {
            scanf("%lld", &a[i]);
            minM = min(minM, a[i]);
            maxM = max(maxM, a[i]);
        }
        ll lo = (N/B) * minM;
        ll hi = (N/B + (N % B > 0)) * maxM;
        ll ans;
        while(lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if(isEnough(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;            
        }
        int beforeMe = (N-1) - countWith(ans - 1);
        for(int i = 0; i < B; i++) {
            if(ans % a[i] == 0 && beforeMe == 0) {
                cout << "Case #" << t << ": " << (i+1) << endl;
                break;
            }
            if(ans % a[i] == 0 ) {
                beforeMe--;                
            }
        }
    }
}
