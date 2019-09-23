#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 3e5;
int dl[N], dr[N];

int main(void) {
    int q;
    scanf("%d", &q);
    memset(dl, 0, sizeof(dl));
    memset(dr, 0, sizeof(dr));
    
    int currL = 0, currR = 0;
    while(q--) {
        char c;
        int id;
        cin >> c >> id;
        if(c == 'R') {
            dl[id] = currR;
            currR++;
            dr[id] = currR * -1;

        } else if(c == 'L') {
            dr[id] = currL;
            currL++;
            dl[id] = currL * -1;
        } else {
            int ans = min(currL + dl[id], currR + dr[id]);
            printf("%d\n",ans);
        }
    }
}