#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int digits[10];

int main() {
    int n; cin >> n;
    string s; cin >> s;    
    memset(digits, 0, sizeof(digits));
    for(int i = 0; i < s.size(); i++) {
        int curr = s[i] - '0';
        switch(curr) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                digits[2]++;
                break;
            case 3:
                digits[3]++;
                break;
            case 4:
                digits[2]+=2;
                digits[3]++;
                break;
            case 5:
                digits[5]++;
                break;
            case 6:
                digits[5]++;
                digits[3]++;
                break;
            case 7:
                digits[7]++;
                break;
            case 8:
                digits[2] += 3;
                digits[7]++;
                break;
            case 9:
                digits[7]++;
                digits[3] += 2;
                digits[2] += 1;
                break;
        }
    }
    string ans = "";
    for(int i = 9; i >= 2; i--) {
        if(digits[i] > 0) ans.append(digits[i], char(i + '0'));
        
    }
    cout << ans << endl;
}