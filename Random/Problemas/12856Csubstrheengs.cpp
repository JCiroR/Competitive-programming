//Many of the language choices were taken from https://github.com/frcepeda/Contest-Archive/blob/master/ACM-ICPC%20Live%20Archive/6823%20-%20Counting%20substhreengs.cpp

#include <cctype>
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
    char act;
    long long res = 0;
    int acum = 0;
    int ce[3];
    ce[0] = 1;
    ce[1] = ce[2] = 0;

    while((act = getchar()) != EOF) {
       if(!isdigit(act)) {
            acum = 0;
            ce[0] = 1;
            ce[1] = ce[2] = 0;
            if(act == '\n') {
                cout << res << "\n";
                res = 0;
            }
            continue;
        }
        acum = (acum + (act - '0')) % 3;
        res += ce[acum];
        ce[acum]++;
    }
    return 0;
}
