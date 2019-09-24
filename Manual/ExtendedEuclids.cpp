/**
 *  ax + by = d
 */
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

//Con struct
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b) {
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

int mod_inv(int a, int m) {
    // solve ax + my = 1, then mod m
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    
    if (g != 1) {
        cout << "No solution!" << endl;
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}

/**
 *  m must be prime, fills mod_inv modulus m for i in [1, m-1]
*/
void fill_mod_inverses(int m) {
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}
