#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

#define pb push_back

using namespace std;
const int MAXN = 1e5+10;
int lis[MAXN];
int lis_id[MAXN];
int P[MAXN];
vector<int> miss;

void printAns(int ind) {
    if(P[ind] != -1) printAns(P[ind]);
    cout << miss[ind] << endl;
}

int main() {
    int t; scanf("%d\n\n", &t);
    while(t--) {
        string s;
        miss.clear();
        while(getline(cin, s) && s.size() > 0) {
            int curr;
            stringstream ss;
            ss << s;
            ss >> curr;
            miss.pb(curr);
            s = "";
        }
        int maX = 0;
        for(int i = 0; i < miss.size(); i++) {
            int ind = lower_bound(lis, lis+maX, miss[i]) - lis;
            lis[ind] = miss[i];
            lis_id[ind] = i;
            P[i] = (ind)? lis_id[ind-1]: -1;
            if(ind == maX) maX++;
        }
        
        cout << "Max hits: "  << maX << endl;
        printAns(lis_id[maX - 1]);
        if(t!=0) cout << endl;
    }
}