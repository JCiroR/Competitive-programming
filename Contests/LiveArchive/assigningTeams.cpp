#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int players[4];
    while(cin >> players[0] >> players[1] >> players[2] >> players[3]) {
        vector<int> lawea(players, players + sizeof(players) / sizeof(int));
        sort(lawea.begin(), lawea.end());
        cout << abs((players[0] + players[3]) - (players[1] + players[2])) << endl;
    }
    return 0;
}