#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 120;

string T, P;
int b[MAX_N], n, m;

void kmpPreprocess() {
    int i = 0, j = -1; b[0] =-1;
    while(i < m) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int kmpSearch() {
    if(T.empty()) return 0;
    int i = 0, j = 0;
    while(i < n) {
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(i == n) return j;
    }
    return 0;
}

int main(void) {
    int cases; cin >> cases;
    while(cases--) {
        int k, w;
        m = n = k;
        cin >> k >> w;
        int length = 0;
        T = "";
        while(w--) {
            n = T.size();
            cin >> P;
            kmpPreprocess();
            length += k - kmpSearch();
            T = P;
        }
        cout << length << endl;
    }
}