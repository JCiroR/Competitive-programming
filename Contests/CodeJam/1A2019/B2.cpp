#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, m;
    cin >> T >> n >> m;
    for(int t = 1; t <= T; t++) {
        int sum = 0;
        for(int night = 0; night < n; night++) {
            for(int i = 0; i < 18; i++) {
                if(i > 0) cout << " ";
                cout << 18;
            }
            cout << endl;
            int nightsAns = 0;
            for(int i = 0; i < 18; i++) {
                int temp;
                cin >> temp;
                nightsAns += temp;
            }
            sum += nightsAns;
        }
        double aux1 = sum, aux2 = n;
        double aux3 = round(sum/aux2);
        int ans = aux3;

        int response; 
        cout << min(ans, m) << endl;
        cin >> response;
        if(response == -1) return 0;
    }
}