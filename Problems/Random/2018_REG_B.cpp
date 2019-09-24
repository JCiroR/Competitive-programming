#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int dis[2 * N + 1], n;

int main() {
    cin >> n;
    int targ = 0;
    for(int i = 0; i < n; i++) {
        cin >> dis[i];
        dis[i + n] = dis[i];
        targ += dis[i];
    }
    if(targ % 2 != 0) {
        cout >> "N\n";
        return 0;
    } else targ /= 2;

    int l = 0, r = 0, sum = 0, lines = 0;
    while(r < 2*n) {
        if(sum < targ) {
            sum += dis[r++];
        } else {
            if(sum == targ) lines++;
            sum -= dis[l++];
        }
    }
    lines /= 2;
    cout << (lines >= 2? "Y":"N") << endl;
}