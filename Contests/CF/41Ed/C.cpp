#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>

using namespace std;
typedef long long ll;
int perm[4] = {0,1,2,3}, n, costB[4], costW[4];
bool tab[4][101][101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                char temp; cin >> temp;
                tab[i][j][k] = (temp == '1');
            }    
    for(int k = 0; k < 4; k++) {
        bool aux = true;
        int cost = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(tab[k][i][j] != aux) cost++;
                aux = !aux;
            }
        costB[k] = cost;
    }
    for(int k = 0; k < 4; k++) {
        bool aux = false;
        int cost = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(tab[k][i][j] != aux) cost++;
                aux = !aux;
            }
        costW[k] = cost;
    }
    int minC = 1000*4*1000, currC;
    do {        
        currC = costB[perm[0]] + costW[perm[1]] + costW[perm[2]] + costB[perm[3]];
        minC = min(minC, currC);
        currC = costW[perm[0]] + costB[perm[1]] + costB[perm[2]] + costW[perm[3]];
        minC = min(minC, currC);
    } while(next_permutation(begin(perm), end(perm)));
    //for(int i = 0; i < 4; i++) cout << costW[i] << " " << costB[i] << endl;
    cout << minC << endl;
}
