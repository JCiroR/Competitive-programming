#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 30005, coins[] = {1, 5, 10, 25, 50}, coins_s = 5;
long long ways[coins_s][MAXN];

long long change(int type, int value) {
    if(value == 0) return 1;
    if(type == coins_s || value < 0) return 0;
    if(ways[type][value] != -1) return ways[type][value];
    return ways[type][value] = change(type, value - coins[type]) + change(type + 1, value);
}

int main(void){
    int value;
    memset(ways, -1, sizeof(ways));
    while(scanf("%d", &value) == 1) {
        long long answ = change(0, value);
        if(answ == 1) printf("There is only 1 way to produce %d cents change.\n", value);
        else printf("There are %lld ways to produce %d cents change.\n", answ, value);
    }
    return 0;
}