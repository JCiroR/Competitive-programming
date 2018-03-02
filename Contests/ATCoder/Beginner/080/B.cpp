#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long x;
    cin >> x;
    long long sum = 0;
    string aux = to_string(x);
    for(int i = 0; i < aux.size(); i++) {
        sum += int(aux[i] - '0');
    }
    if(x % sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}