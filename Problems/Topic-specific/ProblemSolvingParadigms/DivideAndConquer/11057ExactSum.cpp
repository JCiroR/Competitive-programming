#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits.h>

using namespace std;

const int MAXN = 10005;
int prices[MAXN];

int main(void) {
    int N, M;
    while(!cin.eof()) {
        cin >> N; if(cin.eof()) break;
        fill(prices, prices + N, 0);
        for(int i = 0; i < N; i++) scanf("%i", &prices[i]);
        cin >> M;

        sort(prices, prices + N - 1);
        int pr1, pr2, diff = INT_MAX;
        for(int i = 0; i < N; i++) {
            int target = M - prices[i];
            if(abs(target - prices[i]) < diff && binary_search(prices, prices + N - 1, target)) {
                pr1 = min(target, prices[i]);
                pr2 = max(target, prices[i]);
                diff = abs(target - prices[i]);
            }
        }
        printf("Peter should buy books whose prices are %i and %i.\n\n", pr1, pr2);
    }
    return 0;
}