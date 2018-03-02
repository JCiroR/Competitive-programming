#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int n, m, currKey;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        int counter = 0;
        set<int> cds;
        while(n--) {
            cin >> currKey;
            cds.insert(currKey);
        }
        while(m--) {
            cin >> currKey;
            if(cds.count(currKey) > 0) counter++;
        }
        cout << counter << "\n";
    }
    
    return 0;
}