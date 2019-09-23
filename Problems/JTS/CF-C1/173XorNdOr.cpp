#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    bool equal = true;
    int one_a = 0, one_b = 0;
    if(a.size() != b.size()) {
        cout << "NO\n"; return 0;
    }
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) equal = false;
        if(a[i] == '1') one_a++;
        if(b[i] == '1') one_b++;
    }
    if(equal || (one_a && one_b)) cout << "YES\n";
    else cout << "NO\n";
}