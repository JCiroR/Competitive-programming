#include <bits/stdc++.h>
using namespace std;

string s;
int freq[500];
int taken[500];

int main() {
    memset(freq, 0, sizeof(freq));
    memset(taken, 0, sizeof(taken));
    
    int n;
    cin >> n >> s;
    int target = n/3;
    
    for(int i = 0; i < n; i++) freq[s[i]]++;
    int i = 0;
    while(i < n) {
        if(freq[s[i]] > target) {
           for(char c = '0'; c <= '2'; c++) {
               if(freq[c] < target) {
                   freq[s[i]]--;
                   freq[c]++;
                   taken[c]++;
                   s[i] = c;
                   break;
               } else if(c == s[i] && taken[s[i]] < target) {
                   taken[s[i]]++;
                   break;
               }
            }
        }        
        i++;
    }

    cout << s << endl;
}