#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    string s; cin >> s;
    string m = "9223372036854775808";
    if(s.size() < 3 || (s.size() == 3 && stoi(s) <= 127)) cout << "byte";
    else if(s.size() < 5 || (s.size() == 5 && stoi(s) <= 32767)) cout << "short";
    else if(s.size() < 10 || (s.size() == 10 && stoll(s) <= 2147483647LL)) cout << "int";
    else if(s.size() < 19 || (s.size() == 19 && lexicographical_compare(s.begin(), s.end(), m.begin(), m.end())))
        cout << "long";
    else cout << "BigInteger";
    cout << endl;
}

