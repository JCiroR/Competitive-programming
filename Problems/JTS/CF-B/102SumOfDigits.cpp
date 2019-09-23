#include <string>
#include <iostream>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int times = 0;
    while(s.size() > 1) {
        times++;
        int sum = 0;
        for(int i = 0; i < s.size(); i++) sum += (s[i] - '0');
        s = to_string(sum);
    }
    cout << times << endl;
}