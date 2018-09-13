#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;
#define MAXN 100005
int leftSoldier[MAXN];
int rightSoldier[MAXN];

int main(void) {
    int S, B, L, R;
    while(cin >> S >> B) {
        if(S == 0 && B == 0) break;
        for(int i = 0; i < S; i++) {
            rightSoldier[i] = i + 1;
            leftSoldier[i] = i - 1;
        }
        while(B--) {
            cin >> L >> R;
            L--; R--;
            if(leftSoldier[L] >= 0) rightSoldier[leftSoldier[L]] = rightSoldier[R];
            if(rightSoldier[R] < S) leftSoldier[rightSoldier[R]] = leftSoldier[L];

            (leftSoldier[L] >= 0)? cout << leftSoldier[L] + 1 << " ": cout << "* ";
            (rightSoldier[R] < S)?  cout << rightSoldier[R] + 1 << "\n": cout << "*\n";
        }
        cout << "-\n";
    }
    return 0;
}