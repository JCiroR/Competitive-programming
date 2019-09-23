#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>

using namespace std;

int population[25], offices[5], option[5];
int minDistSum;

void clear() {
    for(int i = 0; i < 25; i++) population[i] = 0;
    for(int i = 0; i < 5; i++) offices[i] = i;
}

int distance(int area, int office) {
    return population[area] * (abs(area % 5 - office % 5) + abs(area / 5 - office / 5));
}

void solve(int from, int cIndex) {
    if(cIndex < 5) {
        for(int i = from; i < 25; i++) {
            option[cIndex] = i;
            solve(i + 1, cIndex + 1);
        }
    } else {
        int distSum = 0;
        for(int i = 0; i < 25; i++)
            if(population[i] > 0) {
                int distanceToOffice = INT_MAX;
                for(int j = 0; j < 5; j++)
                    distanceToOffice = min(distanceToOffice, distance(i, option[j]));
                distSum += distanceToOffice;
            }
        if(distSum < minDistSum) {
            minDistSum = distSum;
            for(int i = 0; i < 5; i++)
                offices[i] = option[i];
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        clear();
        int n, x, y;
        cin >> n;
        while(n--) {
            cin >> x;
            cin >> y;
            cin >> population[x * 5 + y];
        }
        minDistSum = INT_MAX;
        solve(0, 0);
        for(int i = 0; i < 5; i++)
            cout << offices[i] << ((i == 4)? "\n":" ");
    }

    return 0;
}