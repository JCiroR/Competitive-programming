#include <vector>
#include <list>
#include <cmath>
#include <iostream>

//Wrong approach to the excercise.

using namespace std;
const int MAXN  = 1 << 3;
int greyCodes[MAXN];

int fillNBitReflectedCode(int nextPos, int neededShifts) {
    int j = nextPos - 1;
    for(int i = nextPos; i < nextPos * 2; i++) {
        greyCodes[i] = (greyCodes[j] | (1 << neededShifts)) ;
        j--;
    }
    return nextPos * 2;
}

int main(void) {
    greyCodes[0] = 0;
    greyCodes[1] = 1;
    int nextPos = 2;
    int neededShifts = 1;
    while(nextPos < MAXN) {
        nextPos = fillNBitReflectedCode(nextPos, neededShifts);
        neededShifts++;
    }
    int testNum, n, k;
    cin >> testNum;
    while(testNum--) {
        cin >> n >> k;
        cout << greyCodes[k] << "\n";
    }

    return 0;
}