#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[361];
int aca[361];

int sum(int i, int j) {
    if(j < i) return 360 - sum(j,i) + a[i] + a[j];
    else if(i > 0) return aca[j] - aca[i-1];
    else return aca[j];
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        aca[i] = a[i];
        if(i > 0) aca[i] += aca[i - 1];
    }
    int diff  = 360;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int curr = abs(360 - 2*sum(i,j));
            diff = min(diff, curr);
        }
    }
    cout << diff << endl;
}
