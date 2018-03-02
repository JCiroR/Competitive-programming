#include <string>
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int f,t;
    char a,b;
    while(m--) {
        cin >> f >> t >> a >> b;
        f--; t--;
        for(int i = f; i <= t; i++) {
            if(s[i] == a) s[i] = b;
        }
    }
    cout << s << endl;
    return 0;
}