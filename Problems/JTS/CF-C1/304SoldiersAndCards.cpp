#include <iostream>
#include <string>
#include <deque>
#include <set>

using namespace std;
deque<int> s1, s2;

string getSt() {
    string ans = "";
    for(auto it = s1.begin(); it != s1.end(); ++it) {
        ans += to_string(*it);
        ans += '|';
    }
    ans += '-';
    for(auto it = s2.begin(); it != s2.end(); ++it) {
        ans += to_string(*it);
        ans += '|';
    }
    return ans;
}

int main() {
    int n, ki, temp;
    cin >> n >> ki;
    while(ki--) {
        cin >> temp;
        s1.push_back(temp);
    }
    cin >> ki;
    while(ki--) {
        cin >> temp;
        s2.push_back(temp);
    }
    set<string> states;
    int fights = 0;
    while(!s1.empty() && !s2.empty()) {
        string state = getSt();
        if(states.count(state) > 0) {
            cout << -1 << endl;
            return 0;
        }
        states.insert(state);
        if(s1.front() > s2.front()) {
            s1.push_back(s2.front());
            s1.push_back(s1.front());
            s1.pop_front();
            s2.pop_front();
        } else {
            s2.push_back(s1.front());
            s2.push_back(s2.front());
            s2.pop_front();
            s1.pop_front();
        }
        fights++;
    }
    cout << fights << " ";
    if(s1.empty()) cout << 2;
    else cout << 1;
    cout << endl;
    
}