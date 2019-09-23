#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1000000;

int f[MAXN];

int main(void) {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> f[i];
    int minC = INT_MAX;
    int index = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += f[i];
        if(i >= k - 1) {
            if(minC > sum) {
                minC = sum;
                index = i - k + 2;
            }
            sum -= f[i - k + 1];
        }
    }
    cout << index << endl;
}