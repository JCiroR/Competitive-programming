#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<unsigned int, int> s;
unsigned int aux[32], a[120010];

int main(void) {
    aux[0] = 1;
    for(int i = 1; i < 32; i++) aux[i] = aux[i-1] * 2;
    int n, ans;
    scanf("%d", &n);
    ans = n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        unsigned int e = a[i], tar;
        for(int j = 1; j < 32; j++) {
            if(aux[j] <= e) continue;
            tar = aux[j] - e;
            int av = 0;
            if(s.count(tar)) av = s[tar];
            // cout << e << " " << tar << " " << av << endl;
            if(av > 0 && (tar != e || av > 1)) {
                ans--;
                break;
            }
        }
    }
    printf("%d\n", ans);
}