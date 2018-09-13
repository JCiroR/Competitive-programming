#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector<int> poly;

int horner(int x) {
    int res = poly[0];
    for(int i = 1; i < poly.size(); i++) {
        res = res * x + poly[i];
    }
    return res;
}

void derivate() {
    int degree = poly.size() - 1;
    for(int i = 0; i < poly.size(); i++) {
        poly[i] *= (degree - i);
    }
    poly.pop_back();
}

int main(void) {
    string l1, l2; int x;
    while(cin >> x) {
        getline(cin, l2);
        getline(cin, l1);
        poly.clear();
        stringstream ss;
        ss << l1; 
        int c; 
        while(ss >> c ) poly.push_back(c); 
        derivate();
        cout << horner(x) << endl;
    }
    return 0;
}