#include <iostream>
#include <climits>

using namespace std;

int main(void)  {
    int n;
    long long v = 0,  temp;
    long long maxCap1 = INT_MIN, maxCap2 = INT_MIN;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v += temp;
    }
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp > maxCap1) {
            maxCap2 = maxCap1;
            maxCap1 = temp;
        } else if(temp > maxCap2) maxCap2 = temp;
    }
    cout <<( (maxCap1 + maxCap2 >= v)? "YES\n":"NO\n" );

    return 0;
}
