#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

const int MAXM = 21;
const int MAXT = 200;

int nums[MAXM];
bool knap[MAXT + 1];

bool func(int target, int n) {
    knap[0] = true;
    for(int i = 0; i < n; i++) for(int j = MAXT; j >= 0; j--) {
        if(knap[j] && j + nums[i] <= MAXT) knap[j + nums[i]] = true;
    }
    return knap[target];
}

int main(void) {
    int m;
    scanf("%d", &m);
    string temp3;
    getline(cin, temp3);
    while(m--) {
        string temp;
        int temp2;
        
        getline(cin, temp);
        memset(nums, 0, sizeof(nums));
        memset(knap, false, sizeof(knap));

        stringstream ss;
        ss << temp;
        int n = 0;
        int total = 0;

        for(int i = 0; ss >> temp2; i++) {
            nums[i] = temp2;
            total += temp2;
            n++;
        }
        
        if(total % 2 == 0 && func(total/2, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
