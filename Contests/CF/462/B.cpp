#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int k; 
    cin >> k;
    if(k > 36) cout << -1;
    else if(k == 1) cout << 6;
    else {     
        string ans = "";
        while(k >= 2) {
            ans.push_back('8');
            k-=2;
        }
        if(k == 1) ans.push_back('0');
        cout << ans << endl;
    }
}