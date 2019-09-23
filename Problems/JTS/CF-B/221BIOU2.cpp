#include <iostream>
#include <cstring>

using namespace std;

int owe[110];

int main() {
    memset(owe, 0, sizeof(owe));
    int n, m;
    cin >> n >> m;
    int ai, bi, ci;
    while(m--) {
        cin >> ai >> bi >> ci;
        ai--; bi--;
        owe[ai] += ci;
        owe[bi] -= ci;
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        if(owe[i] > 0) sum += owe[i];
    cout << sum << endl;
}