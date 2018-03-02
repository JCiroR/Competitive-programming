#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

ll den[110], num[110];

int main(void) {
    ll n, m;
    while(cin >> n >> m && n && m) {
        memset(den, 1, sizeof(den));
        memset(num, 1, sizeof(num));
        ll cancel = max(n - m, m);
        ll remain = min(n - m, m);
        
        for(int i = cancel + 1; i <= n; i++) num[i] = i;
        for(int i = 1; i <= remain; i++) den[i] = i;
        
        for(int i = remain; i >= 2; i--) {
            if(den[i] != 1) {
                for(int j = cancel + 1; j <= n; j++) {
                    if(num[j] != 1 && num[j] % den[i] == 0) {
                        num[j] /= den[i];
                        den[i] = 1;
                    } else if(num[j] != 1 && den[i] % num[j] == 0) {
                        den[i] /= num[j];
                        num[j] = 1;
                    }
                }
            }
        }
        ll ans = 1;
        for(int i = cancel + 1; i <= n; i++) ans *= num[i];
        for(int i = 1; i <= remain; i++) ans /= den[i];
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, ans);
    }
}