#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int n, m, temp;
    cin >> n >> m;
    set<int> a;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a.insert(temp);
    }
    for(int i = 1; m > 0; i++) {
        if(a.count(i)) continue;
        if(m >= i) ans.push_back(i), m -= i;
        else break;
    }
    printf("%lu\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        if(i > 0) printf(" ");
        printf("%d", ans[i]);        
    }
    printf("\n");
}