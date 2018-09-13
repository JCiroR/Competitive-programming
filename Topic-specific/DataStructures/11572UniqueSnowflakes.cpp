#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    int tests, n;
    cin >> tests;
    
    while(tests--) {
        cin >> n;
        int max = 0, currIndex = 1, currKey, lastStart = 1;
        map<int, int> snowflakes;
        while(n--) {
            cin >> currKey;
            if(snowflakes.count(currKey) > 0 && snowflakes[currKey] >= lastStart) {
                max = std::max(max, currIndex - lastStart);
                lastStart = snowflakes[currKey] + 1;
            }
            snowflakes[currKey] = currIndex;
            currIndex++;
        }
        max = std::max(max, currIndex - lastStart);
        cout << max << "\n";
    }
    return 0;
}