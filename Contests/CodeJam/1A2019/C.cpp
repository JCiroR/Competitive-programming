#include <bits/stdc++.h>

using namespace std;

vector<string> arr;
map<string, vector<int> > suffix_ind;
bool used[1001];
int N;

int fun(map<string, vector<int> >::iterator it) {
    if(it == suffix_ind.end()) return 0;
    vector<int> curr = it->second;
    int ans = 0;
    for(int i = 0; i < curr.size(); i++) {
        for(int j = i + 1; j < curr.size(); j++) {
            int w1 = curr[i], w2 = curr[j];
            if(used[w1] || used[w2])
                continue;
            used[w1] = used[w2] = true;

            map<string, vector<int> >::iterator itCopy = it;
            itCopy++;

            ans = 2 + fun(itCopy);
            used[w1] = used[w2] = false;
        }
    }
    map<string, vector<int> >::iterator itCopy2 = it;
    itCopy2++;
    ans = max(ans, fun(itCopy2));
    return ans;
}

int main() {
    int T; cin >> T;
    arr.reserve(1001);
    for(int t = 1; t <= T; t++) {
        arr.clear();
        suffix_ind.clear();
        cin >> N;
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            arr.push_back(s);
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < arr[i].size(); j++) {
                string suffix = arr[i].substr(j);
                suffix_ind[suffix].push_back(i);
            }
        }
        // for(map<string, vector<int> >::iterator it = suffix_ind.begin(); it != suffix_ind.end(); it++) {
        //     cout << it->first << " [ ";
        //     for(int i = 0; i < it->second.size(); i++)
        //         cout << it->second[i] << " ";
        //     cout << "]" << endl;
        // }
        memset(used, false, sizeof(used));
        cout << "Case #" << t << ": " << fun(suffix_ind.begin()) << endl;
    }
}