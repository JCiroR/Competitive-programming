#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    set<int> nums;
    while(n--) {
        cin >> t;
        if(nums.size() < 4) nums.insert(t);
    }
    if(nums.size() == 1 || nums.size() == 2) cout << "YES\n";
    else if(nums.size() > 3) cout << "NO\n";
    else {
        vector<int> aux(nums.begin(), nums.end());
        sort(aux.begin(), aux.end());
        if(aux[1]*2 == aux[0] + aux[2]) cout << "YES\n";
        else cout << "NO\n";
    }
}