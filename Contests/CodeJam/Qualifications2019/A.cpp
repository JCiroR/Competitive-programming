#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int ct = 1; ct <= t; ct++) {
        string in, out1, out2;
        cin >> in;
        out1 = out2 = "";
        for(int i = 0; i < in.size(); i++) {
            if(in[i] == '4') {
                out1.push_back('1');
                out2.push_back('3');
            } else {
                out1.push_back(in[i]);
                if(!out2.empty()) out2.push_back('0');
            }
        }
        cout << "Case #" << ct << ": " << out1 << " " << out2 << endl;
    }
}