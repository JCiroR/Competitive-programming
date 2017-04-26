#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int diff, cr, ct;
    while(cin >> diff >> cr >> ct){
        int tot = cr + ct;
        int curr = 0;
        int rit = 3 + diff;
        for(int i = rit - 1; i > 3; i--) rit += i;
        int teo = 3;
        curr += rit;
        curr += 3;
        rit = 3 + diff;
        while(curr != tot) {
            if(curr == tot) break;
            rit++;
            teo++;
            curr += rit + teo;
        }
        int realRit = (rit * (rit + 1)) / 2;
        realRit -= 6;
        cout << cr - realRit << "\n";
    }

    return 0;
}