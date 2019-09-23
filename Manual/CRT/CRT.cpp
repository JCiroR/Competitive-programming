#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int mod_inv(int a, int m) {
    // solve ax + my = 1, then mod m
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) cout << "No solution!" << endl;
    else {
        x = (x % m + m) % m;
        return x;
    }
}

const int SZ = 20;
ll a_i[SZ], n_i[SZ], y_i[SZ], z_i[SZ];
// x (congruence operator) a_i mod n_i
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll N = 1;
        for(int i = 0; i < n; i++) {
            cin >> a_i[i] >> n_i[i];
            N *= n_i[i];
        }
        for(int i = 0; i < n; i++) {
            y_i[i] = N / n_i[i];
            z_i[i] = mod_inv(y_i[i], n_i[i]);
        }
        ll x = 0;
        for(int i = 0; i < n; i++) {
            x += (a_i[i] * y_i[i] * z_i[i]);
        }
        cout << (x % N)  << " mod " << N << endl;
    }
}