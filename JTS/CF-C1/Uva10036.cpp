#include <cstdio>
#include <cstring>

using namespace std;

int opt[10010], n , k;
short memo[10010][101];

int mod(int b) {
    if(b > 0) return b % k;
    else return ((k-1)* ((-b) % k)) % k;
}

bool dp(int ind, int div) {
    if(ind >= n) return (div == 0);
    short * t = &memo[ind][div];
    if(*t != -1) return *t;

    bool ans = false;
    ans = dp(ind + 1, mod(div + mod(opt[ind])));
    if(!ans) ans |= dp(ind + 1, mod(div + mod(-opt[ind])));
    
    if(ans) return *t = 1;
    else return *t = 0;
}

int main()
{
    int m; scanf("%d",&m);
    while(m--) 
    {
        scanf("%d%d",&n,&k);
        for(int i = 0; i < n; i++) scanf("%d", &opt[i]);
        memset(memo, -1, sizeof(memo));
        if(dp(1, mod(opt[0]))) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}