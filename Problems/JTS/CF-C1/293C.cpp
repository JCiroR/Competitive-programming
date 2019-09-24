#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int pos[MAXN], num[MAXN];
int n, m, k, temp;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i  <= n; i++)
    {
        scanf("%d",&temp);
        pos[temp] = i;
        num[i] = temp;
    }
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {  
        scanf("%d", &temp);
        
        int aux = pos[temp];
        if(aux % k != 0) aux += (k - (aux%k));
        aux /= k;
        ans += aux;
        if(pos[temp] > 1) {
            int targ = num[pos[temp] - 1];
            pos[targ] = pos[temp];
            pos[temp] = pos[targ] - 1;
            num[pos[targ]] = targ;
            num[pos[temp]] = temp;
        }
    }
    printf("%I64d\n", ans);
}