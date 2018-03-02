#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main(void) {
    int B, S, test = 0;
    while((scanf("%i %i", &B, &S))) {
        if(B == 0 && S == 0) break;
        int temp, younger = 61;
        
        for(int i = 0; i < B; i++) {
            scanf("%i", &temp);
            younger = min(younger, temp);
        }
        for(int i = 0; i < S; i++) scanf("%i", &temp);

        if(S >= B) printf("Case %i: 0\n", ++test);
        else printf("Case %i: %i %i\n", ++test, B - S, younger);
    }
    return 0;
}