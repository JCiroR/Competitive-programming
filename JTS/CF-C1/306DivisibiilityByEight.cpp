#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, temp = "";
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n;  i++) {
        temp += s[i];
        if(stoi(temp) % 8 == 0) {
            cout << "YES\n" << stoi(temp) << endl;
            return 0;
        }
        for(int j = i + 1; j < n;  j++) {
            if(temp[0] == '0') break;
            temp += s[j];            
            if(stoi(temp) % 8 == 0) {
                cout << "YES\n" << stoi(temp) << endl;
                return 0;
            }
            for(int k = j + 1; k < n;  k++) {
                temp += s[k];
                if(stoi(temp) % 8 == 0) {
                    cout << "YES\n" << stoi(temp) << endl;
                    return 0;
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        temp.pop_back();
    }
    cout << "NO\n";
}