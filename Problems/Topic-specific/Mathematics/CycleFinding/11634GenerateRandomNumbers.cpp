#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 10010;
bool DAT[MAXN];
int a0;

int f(int x) {
    x *= x;
    string num = to_string(x);
    num.insert(0, 8 - num.size(), '0');
    return stoi(num.substr(2, 4));
}

int main(void) {
    int cases = 0;
    while(scanf("%d", &a0)==1 && a0) {
        fill(DAT, DAT + MAXN, false);
        int it = 0;
        while(true) {
            if(DAT[a0]) break;
            DAT[a0] = true;
            it++;
            a0 = f(a0);
        }
        printf("%d\n", it);
    }
    return 0;
}