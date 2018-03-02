#include <iostream>

using namespace std;

int main(void) {
    long long n,k;
    cin >> n >> k;
    
    long long crossedSticks = n - (n % k);
    long long totalMoves = crossedSticks/ k;

    (totalMoves % 2 == 0)? cout << "NO\n": cout <<"YES\n";

    return 0;
}
