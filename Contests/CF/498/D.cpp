#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
string a, b;
char aux[5];
bool auxB[5];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    int ans = 0;
    for(int l = 1; l <= n; l++) {
        int r = n - l + 1;
        if(l > r) break;
        else if(r == l) {
            if(a[r-1] != b[r-1]) ans++;
            continue;
        } else {
            int match = 0, match2 = 0;
            memset(auxB, true, sizeof(auxB));
            aux[0] = a[l-1];
            aux[1] = a[r-1];
            aux[2] = b[l-1];
            aux[3] = b[r-1];
            for(int i = 0; i < 4; i++) {
                if(!auxB[i]) continue;
                for(int j = 3; j > i; j--) {
                    if(aux[i] == aux[j]) match2++;
                    if(auxB[j] && aux[i] == aux[j]) {
                        match++;
                        auxB[j] = false;
                        auxB[i] = false;
                        break;
                    }
                }
            }
            if(match == 0 || (match == 1 && aux[0] == aux[1] && match2 == 1)) ans += 2;
            else ans += 2 - match;
        }
    }
    cout << ans << endl;
}