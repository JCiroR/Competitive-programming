#include <iostream>
#include <limits.h>

using namespace std;

int divv(int a, int b) {
    if(b == 0) return INT_MAX;
    int c = a/b;
    if(c * b < a) return c + 1;
    else return c;
}

int main(void) {
    int target, m;
    cin >> target >> m;
    int leftMost = 1, rightMost = target;

    int y, x;
    while(m--) {
        cin >> y >> x;
        int pLeft =  divv(y, x); // n >= pLeft
        int pRight = divv(y, x - 1) - 1; // n <= pRight - 1
        if(pLeft > leftMost) leftMost = pLeft;
        if(pRight < rightMost) rightMost = pRight;
    }

    if(leftMost == rightMost)  cout << divv(target, rightMost) << endl;
    else cout << "-1" << endl;


}