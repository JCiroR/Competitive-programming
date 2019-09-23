#include <tuple>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef tuple<int, int, char, int> ev;
bool active[100100];
int eActive = -1, curr_i = 0;
vector<ev> events;
vector<ev> eAct;

void next_eActive() {
    eActive = -1;
    for(int i = curr_i; i < eAct.size(); i++) {
        ev c = eAct[i];
        curr_i = i;
        if(active[get<3>(c)]) {
            curr_i = i;
            eActive = get<0>(c);
            break;
        }
    }    
}

int main() {
    int n; cin >> n;
    int ai, bi;  
    memset(active, false, sizeof(false));
    for(int i = 0; i < n; i++) {
        cin >> ai >> bi;        
        events.push_back(make_tuple(ai, bi, 'i', i));
        events.push_back(make_tuple(bi, ai, 'f', i));
    }
    sort(events.begin(), events.end());
    int ans = 0;
    for(int i = 0; i < events.size(); i++) {
        ev c = events[i];
        if(get<2>(c) == 'i') {
            eAct.push_back(c);
            active[get<3>(c)] = true;
            if(eActive == -1) next_eActive();
        } else {
            active[get<3>(c)] = false;
            if(eActive != -1 && eActive < get<1>(c)) ans++;                
            else next_eActive();            
        }
    }
    cout << ans << endl;
}