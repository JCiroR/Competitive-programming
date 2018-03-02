#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi sorted;
vi initial;

bool checkReverse(int a, int b) {
    for(int i = 0; i <= b - a; i++)
        if(sorted[a + i] != initial[b - i]) return false;
    return true;
}

int main(void) {
    int n;
    cin >> n;
    sorted.assign(n, 0);
    initial.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> initial[i];
        sorted[i] = initial[i];
    }
    sort(sorted.begin(), sorted.end());
    int a = -1, b = -1;
    for(int i = 0; i < n; i++)
        if(initial[i] != sorted[i]) {
            a = i;
            break;
        }
    for(int i = n - 1; i >= 0; i--)
        if(initial[i] != sorted[i]) {
            b = i;
            break;
        }
    if(a == -1 && b == -1) {
        cout << "yes\n" << "1 1\n";
    } else if(checkReverse(a,b)) {
        cout << "yes\n" << a + 1 << " " << b + 1<< endl;
    } else cout << "no\n";
}