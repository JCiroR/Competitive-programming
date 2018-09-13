#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

//Kind of awful code

int minDistance(string str) {
    int mini = 1000000;
    for(int i = 0; i < str.size() - 1; i++) 
        mini = min(abs((int)str[i] - (int)str[i + 1]), mini);
    return mini;
}

int main(void) {
    string input;
    while(cin >> input) {
        string maxS = "";
        int maxMin = -1213131;
        string down = input;
        for(int i = 0; i < 10; i++) {
            prev_permutation(down.begin(), down.end());
            int currMinDist = minDistance(down);
            if(currMinDist > maxMin) {
                maxMin = currMinDist;
                maxS = down;
            }
            if(currMinDist == maxMin) {
                maxS = (down < maxS)? down: maxS;
            }
        }

        for(int i = 0; i < 11; i++) {
            int currMinDist = minDistance(input);
            if(currMinDist > maxMin) {
                maxS = input;
                maxMin = currMinDist;
            }
            if(currMinDist == maxMin) {
                maxS = (input < maxS)? input: maxS;
            }
            next_permutation(input.begin(), input.end());
        }
        cout << maxS << maxMin << "\n";
    }
    return 0;
}