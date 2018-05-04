#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

const int MAXT = 100;
const int MAXP = 100;

int dp[MAXT][MAXP][2];
int p[MAXP], b[MAXP], t[MAXP], n, k, m;;


int fAux(int n) {
    return 1;
}

int main() {    
    cin >> n >> k >> m;
    vector<pair<int, int> > pok;
    int loc, val, eT;
    for(int i = 0; i < m; i++) {
        cin >> loc >> val >> eT;
        p[i] = loc;
        b[i] = val;
        t[i] = eT;
    }
    auto count = 0;
    //fill_n(&dp[0][0][0], MAXT * MAXP * 2, 1);
    fill(&dp[0][0][0], &dp[0][0][0] + MAXT*MAXP*2, -1);
    for(int i = 0; i < MAXT; i++) {
        for(int j = 0; j < MAXP; j++) {
            cout << dp[i][j][1] << " ";
            count++;                                                    
            
        }
        cout << endl;
    }
    cout << count << endl;
}