#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int a[1010], n;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) a[i]--;
    }
    for(int i = 0; i < n; i++) {
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}