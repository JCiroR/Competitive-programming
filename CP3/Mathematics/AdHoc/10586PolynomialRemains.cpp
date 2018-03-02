#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10005;
int poly[MAXN], n, k;

int main(void) {
    while(cin >> n >> k && (n != -1 || k != -1)) {
        memset(poly, 0, sizeof(poly));
        for(int i = 0; i <= n; i++) cin >> poly[i];
        
        for(int i = n; i >= k; i--)
            poly[i-k] -= poly[i];
    
        int max = 0;
        for(int i = 0; i < k && i <= n; i++)
            if(poly[i] != 0) max = i;
        
        cout << poly[0];
        for(int i = 1; i <= max; i++) 
            cout << " " << poly[i];
        
        cout << endl;
    }
    return 0;
}