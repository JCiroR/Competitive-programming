#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool greaterThan(int i, int j) {return i > j;}

int main(void) {
    int N, numOf,temp;
    scanf("%i",&N); numOf = N*2;
    vector<int> players;
    players.reserve(numOf);
    while(numOf--) {
        scanf("%i",&temp);
        players.push_back(temp);
    }
    sort(players.begin(),players.end(), greaterThan);
    (players[N-1] > players[N])? printf("YES\n"):printf("NO\n"); 
    return 0;
}
