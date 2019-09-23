#include <iostream>
#include <vector>

using namespace std;

int x[200];

int main(void) {
    int n, a, temp;
    cin >> n >> a;    
    for(int i = 0; i < n; i++) cin >> x[i];
    a--;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(x[i]) {
            int dist = i - a;
            int j = a - dist;
            if(j < 0 || j >= n || x[j] == x[i]) ans++;
        }
    }
    cout << ans << endl;
}