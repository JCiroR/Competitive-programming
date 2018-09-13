#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1010;
ll p[110];
ll n, k, x, knap[N];

void fun() {
    for(int j = 0; j < k; j++)
        for(int i = N; i >= 0; i--) {
            if(knap[i] > 0 && i + p[j] < N)
                knap[i + p[j]] += knap[i];
        }
}

int main() {
    cin >> x >> n;
    k = 0;
    for(ll i = 1; i < 110; i++) {
        ll val = i;
        for(ll j = 2; j <= n; j++) {
            val *= i;
        }
        p[i-1] = val;
        k++;
        if(val >= x) break;
    }
    memset(knap, 0, sizeof(knap));
    knap[0] = 1;
    fun();
    cout <<  knap[x] << endl;
}