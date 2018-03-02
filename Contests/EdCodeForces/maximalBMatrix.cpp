#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    if(k >  n * n) cout << "-1\n";
    else {
        vector<vector<short> > matrix(n, vector<short>(n, 0));
        int nextDiagonal = 0;
        for(int i = 0; i < n && k > 0; i++) {
            for(int j = 0; j < n && k > 0; j++) {
                if(matrix[i][j] != 1) {
                    if(k > 1) {
                        if(j == i) {matrix[i][j] = 1; k-- ; nextDiagonal++;}
                        else {
                            matrix[i][j] = 1;
                            matrix[j][i] = 1;
                            k -= 2;
                        }
                    } else {
                        matrix[nextDiagonal][nextDiagonal] = 1;
                        k--;
                        nextDiagonal++;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j];
                if(j != n - 1) cout << " "; 
            }
            cout << "\n";
        }
    }
    return 0;
}