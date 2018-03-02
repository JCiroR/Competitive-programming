#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAXN  1000000

using namespace std;

int people[MAXN];

int main(void) {
    int n, L;
    scanf("%i",&n);
    for(int i = 0; i < n; i++) {
        scanf("%i", &L);
        people[i] = L;        
    }

    int min_index = n + 1;
    int count = 0;
    for(int i = n-1; i >= 0; i--) {
        if(min_index > i) count++;
        int target = (i - people[i] >= 0)? i-people[i] : 0;
        min_index = min(min_index, target);
    }
    
    printf("%i\n", count);
    return 0;
}