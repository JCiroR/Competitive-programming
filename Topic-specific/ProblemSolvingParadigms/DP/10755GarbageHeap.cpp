#include <algorithm>
#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 23;
long long gar[MAXN][MAXN][MAXN];


int main(void) {
    int T;
    cin >> T;
    while(T--) {
        int A, B,C;
        cin >> A >> B >> C;
        //Build 3D-sum matrix
        for(int i = 0; i < A; i++) for(int j = 0; j < B; j++)  for(int k = 0; k < C; k++) {
            long long v = 0;
            cin >> v;
            if(i > 0) v += gar[i-1][j][k];
            if(j > 0) v += gar[i][j-1][k];
            if(k > 0) v += gar[i][j][k - 1];
            if(i > 0 && j > 0) v -= gar[i-1][j-1][k];
            if(j > 0 && k > 0) v -= gar[i][j-1][k-1];
            if(i > 0 && k > 0) v -= gar[i-1][j][k-1];
            if(i > 0 && j > 0 && k > 0) v += gar[i-1][j-1][k-1];
            gar[i][j][k] = v;
        }
        long long maxSum = LLONG_MIN;
        
        for(int i = 0; i < A; i++) for(int j = 0; j < B; j++)  for(int k = 0; k < C; k++)
         for(int i1 = i; i1 < A; i1++) for(int j1 = j; j1 < B; j1++)  for(int k1 = k; k1 < C; k1++) {
            long long curr = 0;
            curr += gar[i1][j1][k1];
            if(i > 0) curr -= gar[i-1][j1][k1];
            if(j > 0) curr -= gar[i1][j-1][k1];
            if(k > 0) curr -= gar[i1][j1][k-1];
            if(i > 0 && j > 0) curr += gar[i-1][j-1][k1];
            if(i > 0 && k > 0) curr += gar[i-1][j1][k-1];
            if(j > 0 && k > 0) curr += gar[i1][j-1][k-1];
            if(i > 0 && j > 0 && k > 0) curr -= gar[i-1][j-1][k-1];
            
            if(maxSum < curr) maxSum = curr;
         }
         cout << maxSum << endl;
         if(T) cout << endl;
    }
    return 0;
}