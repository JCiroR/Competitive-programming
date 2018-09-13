//Evaluate, differentiate polynomial.
int horner(int poly[], int n, int x)
{
    int result = poly[0];  // Coefficient of x^n 
    for (int i=1; i<n; i++)
        result = result*x + poly[i];
    return result;
}

void derivate() {
    int degree = poly.size() - 1;
    for(int i = 0; i < poly.size(); i++) {
        poly[i] *= (degree - i);
    }
    poly.pop_back();
}

//mod for neg numbers
typedef long long ll;
const ll MOD = 1e9 + 7;
ll mod(ll b, ll MOD) {
    if(b >= 0) return b % MOD;
    else return ((MOD - 1) * ((-b) % MOD)) % MOD;
}

//Convert a number from radix 10 to any-other.
string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string toRadix(int number, int radix) {
    if(number == 0) return "0";
    string rep = "";
    while(number) {
        rep += digits[number % radix];
        number /= radix;
    }
    reverse(rep.begin(), rep.end());
    return rep;
}

// GCD and LCM
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

//Fast modular exponentiation (x ** y) % p
 int fast_exp(int x, unsigned int y, int p) {
    int res = 1;
    // Update x if it is more than or equal to p
    x = x % p;
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res*x) % p;
        // y must be even now
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}

//Explore implicit 2D grid
//          S,SE,E,NE, N,NW, W,SW neighbors
int dr[] = {1, 1,0,-1,-1,-1, 0, 1}; 
int dc[] = {0, 1,1, 1, 0,-1,-1,-1}; 

//Only 4 ways
//          S E  N  W
int dr[] = {1,0,-1, 0};
int dc[] = {0,1, 0,-1};


int floodfill(int r, int c, char c1, char c2) { // returns the size of CC 
    if (r < 0 || r >= R || c < 0 || c >= C) return 0; // outside grid 
    if (grid[r][c] != c1) return 0; // does not have color c1 
    int ans = 1; // adds 1 to ans because vertex (r, c) has c1 as its color 
    grid[r][c] = c2; // now recolors vertex (r, c) to c2 to avoid cycling! 
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans; // the code is neat due to dr[] and dc[]
}

//Use priority queue with custom comparation
typedef int Foo
class Compare {
    public:
        bool operator() (Foo, Foo) {
            return true;
        }
};
// Without class
#include <functional>
bool Compare(Foo, Foo) {   
    return true;
}
//Usage
int main()
{
    std::priority_queue<Foo, std::vector<Foo>, Compare> pq;
    std::priority_queue<Foo, std::vector<Foo>, std::function<bool(Foo, Foo)>> pq(Compare);
    return 0;
}

//Combinations
double comb[110][110];

void fill() {
    for(ll n = 0; n <= 100; n++) {
        comb[n][n] = 1;
        for(ll c = 1; c <= n; c++) {
            comb[n][n - c] = (n - c + 1) * comb[n][n - c + 1];
            comb[n][n - c] /= c;
        }
    }
}