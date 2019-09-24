#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char complement(char in) {
    if(in == 'S') return 'E';
    else return 'S';
}

int main() {
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        string ans; 
        cin >> n >> ans;
        transform(ans.begin(), ans.end(), ans.begin(), complement);
        cout << "Case #" << t << ": " << ans << endl;
    }
}