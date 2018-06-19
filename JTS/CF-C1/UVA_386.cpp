#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > trip;
typedef long long ll;
vector<trip> sol[210];

int main() {
    for(int i = 2; i <= 200; i++) {
        int b = i * i * i;
        for(int j = i; j <= 200; j++) {
            int c = j * j *j;
            for(int k = j; k <= 200; k++) {
                int d = k * k * k;
                int a = (int)(round(cbrt(b + c + d))); 
                if(a*a*a == b + c + d && a <= 200)  {
                    sol[a].push_back(trip(i, make_pair(j, k)));
                }
            }
        }
    }
    for(int i = 1; i <= 200; i++) {
        for(int j = 0; j < sol[i].size(); j++) {
            printf("Cube = %d, Triple = (%d,%d,%d)\n", i, sol[i][j].first, sol[i][j].second.first, sol[i][j].second.second);
        }
    }
}
