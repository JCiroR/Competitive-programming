#include <iostream>
#include <cstring>

using namespace std;

int arr[1010];

void generate(int left, int right, int tot) {
    if(left > right) return;
    if(tot == 0) return;
    int def = tot / (right - left + 1);
    tot -= def * (right - left + 1); 
    for(int i = left; i <= right; i++) {        
        arr[i] += def;
        if(tot > 0) {
            arr[i]++;
            tot--;
        }
    }
}

int main() {
    memset(arr, 0, sizeof(arr));
    int n, k, l, r, sAll, sK;
    cin >> n >> k >> l >> r >> sAll >> sK;
    generate(0, k-1, sK);
    sAll -= sK;
    generate(k, n-1, sAll);
    cout << arr[0];
    for(int i = 1; i < n; i++)
        cout << " " << arr[i];
    cout << endl;
}