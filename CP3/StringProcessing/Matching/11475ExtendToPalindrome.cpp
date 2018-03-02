#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 100010;

string P, T;
int b[MAX_N], n, m;

void kmpPreprocess() {
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++; j++; 
    b[i] = j; 
  }
}

int kmpSearch() {
  int i = 0, j = 0;
  while (i < n) { 
    while (j >= 0 && T[i] != P[j]) j = b[j]; 
    i++; j++;
    if(i == n) return j;
  }
  return 0;
}

int main(void) {
    while(cin >> T) {
        m = n = T.size();
        P = T;
        reverse(P.begin(), P.end());
        kmpPreprocess();
        int matches = kmpSearch();
        cout << T + P.substr(matches) << endl; 
    }
}