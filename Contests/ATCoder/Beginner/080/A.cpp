#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int MAXT = 100000;
const int MAXC = 50;
int rec[MAXC];

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b) {
        if(a.first > b.first) return true;
        else if(b.first > a.first) return false;
        else if(a.second < b.second) return true;
        return false;
    }
};


priority_queue<pair<int,int>, vector<pair<int,int> >, Compare > Q;
queue<pair<int,int> > A;


int main() {
    memset(rec, -1, sizeof(rec));
    Q = priority_queue<pair<int,int> , vector<pair<int,int> >, Compare >();
    A = queue<pair<int,int> >();
    int N, C, s, t, c;
    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> s >> t >> c;
        Q.push(make_pair(s-1,t-1));
    }
    
    int maxR = 0; int next = 0;
    for(int t = 0; t <= MAXT && !Q.empty(); t++) {
        for(int i = MAXC-1; i >= 0; i--) {
            if(rec[i] < t && rec[i] >= 0) {
                //cout << "remove " << i << " in " << t << " cz " << rec[i] << endl;
                next--;
                rec[i] = -1;
            }
        }
        pair<int,int> aux2 = Q.top();
        while(aux2.first  == t && !Q.empty()) {
            //cout << aux2.first << " " << aux2.second << endl;
            A.push(aux2);
            Q.pop();
            if(!Q.empty())aux2 = Q.top();
        }
        while(!A.empty()) {
            pair<int,int> curr = A.front();
           // cout << curr.first << " " << curr.second << " t: " << t << endl; 
            A.pop();
            rec[next] = curr.second;
            next++;
            maxR = max(maxR, next);
        }
    }
    cout << maxR << endl;
}