#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int MAXN = 300010;
bool righT[MAXN], lefT[MAXN];
int n, m;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(lefT, false, sizeof(lefT));
    memset(righT, false, sizeof(righT));
    cin >> n >> m;
    cin >> s;

    int points = 0, segm = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            points++;
            if(!lefT[i]) segm++;
            if(i > 0) righT[i - 1] = true;
            if(i < n - 1) lefT[i + 1] = true;
        }                
    }

    while(m--) {
        int ind; char c;
        cin >> ind >> c;
        ind--;
        if(s[ind] == '.' && c != '.') {
            points--;
            if(lefT[ind] && righT[ind]) segm++;
            else if(!lefT[ind] && !righT[ind]) segm--;
            if(ind > 0) righT[ind - 1] = false;
            if(ind < n - 1) lefT[ind + 1] = false;
        } else if(s[ind] != '.' && c == '.') {
            points++;
            if(lefT[ind] && righT[ind]) segm--;
            else if(!lefT[ind] && !righT[ind]) segm++;    
            if(ind > 0) righT[ind - 1] = true;
            if(ind < n - 1) lefT[ind + 1] = true;
        }
        s[ind] = c;
        cout << points - segm << endl;
    }
}