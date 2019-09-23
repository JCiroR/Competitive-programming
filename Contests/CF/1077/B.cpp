#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int a[110];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin  >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int k = 0;
    for(int i = 1; i + 1 < n; i++) {
        if(a[i-1] == 1 && a[i+1] == 1 && a[i] == 0) {
            k++;
            a[i+1] = 0;
        }
    }
    cout << k << endl;
}