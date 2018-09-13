#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= 100; j++) {
        if((i&1) && !(j&1)) cout << i << " " << j << endl;
    }
}