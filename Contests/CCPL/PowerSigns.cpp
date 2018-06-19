#include <string>
#include <cstring>
#include <iostream>

using namespace std;
const int MAXN = 50010;
int lefT[MAXN];

int main() 
{
    string s;
    while(cin >> s) 
    {
        int n = s.size();
        if(n == 1 && s[0] == '0') break;
        memset(lefT, 0, sizeof(lefT));
        int currL = 1;
        for(int i = 1; i < n; i++) {
            lefT[i] = currL;
            if(s[i] == '0') currL = 0;
            else currL++;
        }
        bool first = false;
        int skip = n + 2;
        for(int i = n - 1; i >= 0; i--) {
            if(i >= skip) {
                s[i] = '0';
                continue;
            }
            if(s[i] == '1' && lefT[i] > 0) {
                if(lefT[i] > 1 || i - lefT[i] - 1 >= 0) {
                    s[i] = '-';
                    if(i - lefT[i] - 1 < 0) first = true;
                    else s[i- lefT[i] - 1] = '1';
                    skip = i - lefT[i];              
                }
            }
        }
        for(int i = 0; i < n; i++) 
            if(s[i] == '1') s[i] = '+';
        if(first) cout << '+';
        cout << s << endl;
    }
}