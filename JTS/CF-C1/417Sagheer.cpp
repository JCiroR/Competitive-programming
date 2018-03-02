#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100010;
typedef long long ll;

ll prices[MAXN], currK[MAXN];
ll maxK = 0, maxP = 0;
int n, S;

bool evaluate(int k) {
    for(int i = 0; i < n; i++)
    {
        currK[i] = prices[i] + (i + 1) * (ll)k;
    }
    sort(currK, currK + n);
    ll curr = 0;
    for(int i = 0; i < k; i++) 
    {        
        curr += currK[i];
        if(curr > S) break;
    }
    if(curr <= S) {
        if(maxK < k) {
            maxK = k;
            maxP = curr;
        }
        return true;
    }
    return false;
}

int main() {
    cin >> n >> S;
    for(int i = 0; i < n;i++) cin >> prices[i];
    int L = 0, R = n + 1;
    while(L < R - 1) {
        int mid = (L + R)/2;        
        if(evaluate(mid)) L = mid;
        else R = mid;
    }
    cout << maxK << " " << maxP << endl;
}

