#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ll p, q;
	cin >> p >> q;
	string aux = to_string(p);
	ll nines = 0, currNines = 0;
	bool still = true;
	for(int i = aux.size() - 1; i >= 0; i--) {
		if(aux[i] == '9' && still) nines++;
		else still = false;
	}
	//cout << nines << endl;
	ll lim = p - q, mul = 10, ans = p;
	for(int k = 1; k < aux.size(); k++) {
		if(p - (p % mul) - 1 >= lim) {
			ans = p - (p % mul) - 1;
			currNines = k;
		}
		mul *= 10;
	}		
	//cout << currNines << endl;
	if(currNines <= nines) cout << p << endl;
	else cout << ans << endl;
}
