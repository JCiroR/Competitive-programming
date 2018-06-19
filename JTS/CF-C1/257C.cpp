#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MAX_N 2

using namespace std;
typedef long long ll;
struct Matrix { ll mat[MAX_N][MAX_N]; };

const ll MOD = 1e9 + 7;

ll mod(ll b, ll n) {
    if(b >= 0) return b % n;
    else {
        return ((n - 1) * ((-b) % n)) % n;
    }
}

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans; int i, j, k;
    for(i = 0; i < MAX_N; i++)
        for(j = 0; j < MAX_N; j++)
            for(ans.mat[i][j] = k = 0; k < MAX_N; k++) {
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
                ans.mat[i][j] += mod(mod(a.mat[i][k], MOD)  * mod(b.mat[k][j],MOD), MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
    return ans;
}

Matrix matPow(Matrix base, int p) {
    Matrix ans; int i, j;
    for(i = 0; i < MAX_N; i++) for(j = 0; j < MAX_N; j++)
        ans.mat[i][j] = (i == j);
    while(p) {
        if(p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

int main() {
    ll f1, f2, n;
    cin >> f1 >> f2 >> n;
    Matrix aux, func;
    aux.mat[0][0] = aux.mat[1][0] = 1;
    aux.mat[0][1] = -1;
    aux.mat[1][1] = 0;
    func.mat[0][0] = f2;
    func.mat[1][0] = f1;
    aux = matPow(aux, n - 1);
    Matrix ans = matMul(aux, func);
    cout << ans.mat[1][0] << endl;
}