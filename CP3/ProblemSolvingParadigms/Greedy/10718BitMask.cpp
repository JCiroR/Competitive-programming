#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(void) {
    unsigned int N, L, U;
    while(scanf("%u %u %u", &N, &L, &U) != EOF) {
        unsigned int answ = 0;
        for(int i = 31; i >= 0; i--) {
            bool set = (N & (1 << i));
            if(set) {
                unsigned int maxWithoutSetting = (answ| ((1 << i)-1));
                if(maxWithoutSetting < L) answ |= (1 << i);
            } else {
                unsigned int candidate = answ | (1 << i);
                if(candidate <= U) answ = candidate;
            }
        }
        cout << answ << endl;        
    }
}