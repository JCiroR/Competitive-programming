#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int freq[N], a[N], n, k, asize;
int aux[N];

bool eval(int num, bool print) {
    int auxsize = 0;
    int i = 0;
    while(auxsize < k && i < asize) {
        int curr = freq[a[i]];
        while(curr >= num) {
            curr -= num;
            aux[auxsize++] = a[i];
            if(auxsize == k) break;
        }
        i++;
    }
    if(auxsize != k) return false;
    if(print) {
        for(int j = 0; j < auxsize; j++) {
            if(j > 0) printf(" ");
            printf("%d", aux[j]);
        }
        printf("\n");
    }
    return true;
}

bool greatByFreq(int a, int b) {
    return freq[a] > freq[b];
}

int main () {
    memset(freq, 0, sizeof(freq));
    scanf("%d %d", &n, &k);
    int l = 1, r = 1, ans = 1;
    
    asize = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[asize]);
        freq[a[asize]]++;
        if(freq[a[asize]] == 1) asize++;
        r = max(r, freq[a[asize]]);
    }
    sort(a, a + asize, greatByFreq);

    while(l < r) {
        int mid = (r- l) + l;
        bool fun = eval(mid, false);
        if(fun) {
            ans = max(ans, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    eval(ans, true);
}