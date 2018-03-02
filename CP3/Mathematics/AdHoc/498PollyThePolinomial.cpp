#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector<int> coefficients;

int horner(int x) {
    int res = coefficients[0];
    for(int i = 1; i < coefficients.size(); i++) {
        res = res * x + coefficients[i];
    }
    return res;
}


int main(void) {
    string l1, l2;
    while(getline(cin, l1)) {
        coefficients.clear();
        stringstream ss;
        ss << l1; 
        int temp;
        while(ss >> temp) coefficients.push_back(temp);
        getline(cin, l2);
        stringstream ss2;
        ss2 << l2;
        int out = 0;
        while(ss2 >> temp) {
            if(out > 0) cout << " ";
            cout << horner(temp);
            out++;
        }
        cout << endl;
    }
    return 0;
}