#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > trip;
typedef long long ll;

int main() {
    for(int i = 2; i <= 200; i++) {
        int a = i * i * i;
        for(int j = 2; 2 <= 200; j++) {
            int b = j * j * j;
            if(b >= a) break;
            for(int k = j; k <= 200; k++) {
                int c = k * k * k;
                if(b + c >= a) break;
                for(int l = k; l <= 200; l++) {
                    int d = l * l * l;
                    if(b + c + d == a) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                    }
                } 
            }
        }
    } 
}
