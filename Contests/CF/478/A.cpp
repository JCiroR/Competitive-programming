    #include <iostream>
    #include <string>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <set>
    using namespace std;
    typedef long long ll;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n; cin >> n;
        set<string> ans;
        while(n--) {
            string temp;
            cin >> temp;
            set<char> aux;
            for(int i = 0; i < temp.size(); i++) {
                aux.insert(temp[i]);
            }
            string aux2(aux.begin(), aux.end());
            ans.insert(aux2);
        }
        cout << ans.size() << endl;
    }