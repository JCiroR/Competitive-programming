#include <cstring>
#include <cstdio>
#include<iostream>

using namespace std;
typedef int ll;

const int MAXN = 1e6 + 10;
ll f[MAXN];

int main() {
	int n; cin >> n;
	int temp, ans = 0;
 	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		ans ^= temp;
	}
	f[0] = 0;
	for(int i = 1; i <= n; i++) f[i] = f[i - 1] ^ i; 
	for(int i = 0; i < n; i++) {
		ll c = f[n % (i + 1)];
		if( (n/(i+1)) % 2 != 0) c ^= f[i]; 
		ans ^= c;
	}
	cout << ans << endl;
}
