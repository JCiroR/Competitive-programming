#include <bits/stdc++.h>
using namespace std;

const int N = 10;
string num[N], curr = "abcd";
int b[N], c[N], n;

bool checkCurr(int rule){
    string & s = num[rule];
    int bulls = 0, cows = 0;
    for(int i = 0; i < 4; i++) 
        if(s[i] == curr[i]) bulls++;
        else if(s.find(curr[i]) != string::npos) cows++;
    return bulls == b[rule] && cows == c[rule];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i] >> b[i] >> c[i];
    }
    set<string> ans;
    for(curr[0] = '0'; curr[0] <= '9'; curr[0]++) for(curr[1] = '0'; curr[1] <= '9'; curr[1]++) 
        for(curr[2] = '0'; curr[2] <= '9'; curr[2]++) for(curr[3] = '0'; curr[3] <= '9'; curr[3]++)  {
            if(curr[0] == curr[1] || curr[0] == curr[2] || curr[0] == curr[3] || curr[1] == curr[2] || curr[1] == curr[3] || curr[2] == curr[3]) continue;

            bool passes = true;
            for(int i = 0; i < n; i++)
                passes &= checkCurr(i);
            if(passes) ans.insert(curr);
        }

    if(ans.size() == 0) cout << "Incorrect data\n";
    else if(ans.size() == 1) cout << (*ans.begin()) << endl;
    else cout << "Need more data\n";
}