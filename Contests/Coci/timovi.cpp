#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    long long n, k, m;
    cin >> n >> k >> m;    
    vector<ll> ints(n, ((m/(k*n)) * k));
    ll times = m/(k*n);
    m -= (k*n) * times;
    
    
    if(times > 0) {
        ints[ints.size() - 1] -= (times/2) * k; m += (times/2) * k;
        if(times & 1) {
            ints[0] -= (times/2) * k; 
             m += (times/2) * k;
        } else {
            ints[0] -= ((times/2) - 1) * k; 
            m += ((times/2) - 1) * k;    
        }      
    }
    while(m > 0) {
        if(times == 0) {
            for(int i = 0; i < ints.size() && m > 0; i++) {
                if(m > k) {
                    ints[i] += k;
                    m -= k;
                } else {
                    ints[i] += m;
                    m = 0;
                }
            }
            times++;
        } else if((times + 1) & 1) {
            for(int i = 1; i < ints.size() && m > 0; i++) {
                if(m > k) {
                    ints[i] += k;
                    m -= k;
                } else {
                    ints[i] += m;
                    m = 0;
                }
            }
            times++;
        } else {            
            for(int i = ints.size() - 2; i >= 0 && m > 0; i--) {
                if(m > k) {
                    ints[i] += k;
                    m -= k;
                } else {
                    ints[i] += m;
                    m = 0;
                }
            }
            times++;
        }
    }
    cout << ints[0];
    for(int i = 1; i < ints.size(); i++)
        cout << " " << ints[i];
    cout << endl;
}