#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, m;
    cin >> T >> n >> m;
    for(int t = 1; t <= T; t++) {
        map<int, int> auxMap;

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
            auxMap[nightsAns] += 1;
        }

        int ans = 0;
        int maxFreq = 0;
        for(map<int,int>::iterator it = auxMap.begin(); it != auxMap.end(); it++) {
            if(it->second > maxFreq) {
                maxFreq = it->second;
                ans = it->first;
            }
        }
        int response; 
        cout << min(ans, m) << endl;
        cin >> response;
        if(response == -1) return 0;
    }
}