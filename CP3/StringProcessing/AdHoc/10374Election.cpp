#include <string>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

map<string, int> votes;
map<string, string> allies;

int main(void) {
    int T;
    cin >> T;
    while(T--) {
        votes.clear();
        allies.clear();
        int n; cin >> n;
        string name, ally, trash;
        getline(cin,trash);
        for(int i = 0; i < n; i++) {
            getline(cin, name);
            getline(cin, ally);
            votes[name] = 0;
            allies[name] = ally;
        }
        int v; cin >> v;
        getline(cin, trash);
        while(v--) {
            getline(cin, name);
            if(votes.count(name) > 0) votes[name]++;
        }
        string one = "", two = "";
        int max = -1, s_max = -1;
        for(auto it = votes.begin(); it != votes.end(); ++it) {
            if(it->second > max) {
                two = one;
                s_max = max;
                one = it->first;
                max = it->second;
            } else if(it->second > s_max) {
                two = it->first;
                s_max = it->second;
            }
        }
        if(max == s_max) cout << "tie\n";
        else cout << allies[one] << endl;
        if(T) cout << endl;
    }
}