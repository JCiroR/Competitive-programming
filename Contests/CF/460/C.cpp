#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int above[2001];

int main(void) {
    int n, m, k;
    memset(above, 0, sizeof(above));
    scanf("%d %d %d\n", &n, &m, &k);
    long long ans = 0;
    char curr;
    for(int i = 0; i < n; i++) {
        int toLeft = 0;
        for(int j = 0; j < m; j++) {            
            scanf("%c", &curr);            
            if(curr == '*') { 
                toLeft = 0;
                above[j] = 0;
            } else { 
                toLeft++;
                above[j]++;
                if(toLeft >= k) ans++;
                if(k != 1 && above[j] >= k) ans++;
            }
        }
        scanf("\n");
    }
    cout << ans << endl;
}