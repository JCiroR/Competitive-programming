#include <string>
#include <iostream>

using namespace std;

string a, b;
int f[200010];

int main() {
    cin >> a >> b;
    long long dis = 0, total = 0;
    f[0] = (b[0] == '1')? 1: 0;
    for(int i = 1; i < b.size(); i++) {
        f[i] = f[i-1] + ((b[i] == '1')? 1: 0);
    }
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '1') {
            total += b.size() - a.size() + i + 1 - f[b.size() - a.size() + i];
            if(i > 0) total -= i - f[i-1];
        } else {
            total += f[b.size() - a.size() + i];
            if(i > 0) total -= f[i - 1];
        }
    }
    cout << total << endl;
}