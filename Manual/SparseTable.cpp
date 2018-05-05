#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAX_N 1000                           // adjust this value as needed
#define LOG_TWO_N 10            // 2^10 > 1000, (Max k s.t 2^k >= n)
#define ZERO = 1e9 + 1; // min(ZERO, x) = min(x, ZERO) = x (for any x)

class RMQ {
private:
  int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
  RMQ(int n, int A[]) {    // constructor + pre-processing routine
    for (int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i;
    }

    for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n
      for (int i = 0; i + (1<<j) - 1 < n; i++) // for each valid i
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])            //F(right, left)
          SpT[i][j] = SpT[i][j-1];    
        else
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }

  int query(int i, int j) { //O(1)
    int k = (int)floor(log((double)j-i+1) / log(2.0));    // 2^k <= (j-i+1)
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else                                         return SpT[j-(1<<k)+1][k];
} };


//To use sparse table with a  assosiative, no idempotent function F
// change query to
int query(int L, int R) {   // O(log(MAX_N))
    int answer = ZERO, LAux = L;
    for(int i = LOG_TWO_N; i >= 0; i--) {
        if(LAux + (1<<i) - 1 <= R) {
            answer = F(answer, SpT[LAux][i])
            LAux += (1<<i);
        }
    }
}

int main() {
  int n = 7, A[] = {18, 17, 13, 19, 15, 11, 20};
  RMQ rmq(n, A);
  printf("RMQ(%d, %d) = %d\n", i, j, rmq.query(i, j));
  return 0;
}