#include <cstdio>

using namespace std;

int main(void) {
    long long n, k;
    while(scanf("%lld %lld", &n, &k) == 2) {
        long long tot = 0;
        long long b = 0;
        while(n > 0) {            
            tot += n;
            b += n % k;
            n = n/k;
            if(b >= k) {
                n += b / k;
                b = b % k; 
            }
        }
        printf("%lld\n", tot);
    }
    return 0;
}