#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 6000;
int freq[N];
int col_freq[N];
int a[N], col[N];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(freq, 0, sizeof(freq));
    memset(col_freq, 0, sizeof(col_freq));
    int n, k; cin >> n >> k;
    
    int maxUsed = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
        if(freq[a[i]] > k) {
            cout << "NO\n";
            return 0;
        }
        col[i] = freq[a[i]];
        maxUsed = max(maxUsed, col[i]);
        col_freq[col[i]]++;
    }
    for(int i = 0; i < n && maxUsed < k; i++) {
        if(col_freq[col[i]] > 1) {
            col_freq[col[i]]--;
            col[i] = maxUsed + 1;
            col_freq[col[i]]++;
            maxUsed = maxUsed + 1;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << " ";
        cout << col[i];
    }
    cout << endl;
}