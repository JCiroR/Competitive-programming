#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int p[6];

bool greaterThan(int i, int j) {return i > j;}

int main(void) {
    string a;
    int sumL = 0, sumR = 0;
    cin >> a;
    for(int i = 0; i < 3; i++) sumL += a[i] - '0';
    for(int i = 3; i < 6; i++) sumR += a[i] - '0';
    int diff = abs(sumL-sumR);
    
    if(sumL > sumR ) {
        for(int i = 0; i < 3; i++)
            p[i] = a[i] - '0';
        for(int i = 3; i < 6; i++)
            p[i] = 9 - (a[i] - '0');
    } else  if(sumL < sumR) {
        for(int i = 0; i < 3; i++)
            p[i] = 9 - (a[i] - '0');
        for(int i = 3; i < 6; i++)
            p[i] = a[i] - '0';
    }
    if(diff == 0) cout << "0" << endl; 
    else {
        sort(p, p + 6, greaterThan);
        if(diff<= p[0]) cout << "1\n";
        else if(diff <= p[0] + p[1]) cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}