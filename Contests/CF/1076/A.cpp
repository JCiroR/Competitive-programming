#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin >> n >> s;
    int removed = -1;
    for(int i = 0; i + 1 < s.size(); i++) {
        if(s[i] > s[i+1]) {
            removed = i;
            break;
        }
    }
    if(removed == -1) removed = s.size() -1;

    for(int i = 0; i < s.size(); i++) {
        if(i == removed) continue;
        cout << s[i];
    }
    cout << endl;
    

}