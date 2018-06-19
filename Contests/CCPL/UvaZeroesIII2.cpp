#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, b;
    while(cin >> n >> b && (n || b)) {
        ll ans = LONG_LONG_MAX;
        for(ll i = 2; i <= b; i++) {
            if(b % i == 0) {
                int times = 0;
                while(b % i == 0) {
                    b /= i;
                    times++;
                }
                ll currAns = 0, a = i;
                 while(a <= n) {
                    //Taken from wolfram(I wanted to see if this would work):
                    //https://www.wolframalpha.com/input/?i=sum+(sum+i,+i%3D1+to+n-j+*+a+%2B1),+j+%3D+1+to+b
                    ll b = n/a, sum;
                    sum = a*a*(2*b*b + 3*b + 1);
                    sum -= 3*a * (b + 1) * (2*n + 3);
                    sum += 6 * (n*n + 3 * n + 2);
                    sum *= b;
                    sum /= 12;
                    currAns += sum;
                    a *= i;
                }
                ans = min(ans, currAns/times);                
            }
        }
        cout << ans << endl;
    }
}