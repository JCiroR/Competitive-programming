#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, a, t = 0;
vector<int> ans;

int main(void) {
    cin >> n;
    int numb = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == 1) t++;
        if(a == 1 && numb != 0)  {
            ans.push_back(numb);
            numb = 0;
        }
        numb++;
    }
    ans.push_back(numb);
    cout << t << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}