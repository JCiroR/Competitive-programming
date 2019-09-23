#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;
const int MAXN  = 1 << 10;
int main(void) {
    int T, N, M, currWithdrawn;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        int walkOvers = 0;
        int currRoundSize = 1 << N;
        bitset<MAXN> matches;
        matches.set();
        while(M--) {
            cin >> currWithdrawn;
            currWithdrawn--;
            matches.reset(currWithdrawn);
        }
        while(currRoundSize > 1) {
            int j = 0;
            for(int i = 0; i < currRoundSize; i = i + 2) {
                if(matches[i] ^ matches[i + 1]) walkOvers++;
                matches[j] = matches[i] | matches[i + 1];
                j++;
            }
            currRoundSize /= 2;
        }
        cout << walkOvers << "\n";
    }
    return 0;
}