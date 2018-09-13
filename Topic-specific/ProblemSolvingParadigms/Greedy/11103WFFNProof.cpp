#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
    string a;
    while(cin >> a) {
        if(a == "0") break;
        string root = "", neg = "", binary = "";
        for(int i = 0; i < a.size(); i++) {
            if('p' <= a[i] && a[i] <= 't') root += a[i];
            else if(a[i] == 'N') neg += a[i];
            else binary += a[i];
        }
        if(root.size() == 0) cout << "no WFF possible\n";
        else {
            string answ = ""; answ = neg + root[0];
            int i = 1, j = 0;
            while(i < root.size() && j < binary.size()) {
                answ = binary[j] + (root[i] + answ);
                i++; j++;
            }
            cout << answ << endl;
        }
    }
}