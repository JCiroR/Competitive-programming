#include <set>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 2001;

int ka[MAXN];
int ko[MAXN];

int main(void) {
    int n;
    scanf("%d", &n);
    set<int> nums;
    for(int i = 0; i < n; i++) {
        scanf("%d", &ka[i]);
        nums.insert(ka[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &ko[i]);
        nums.insert(ko[i]);
    }
    int pairs = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        int x = (ka[i] ^ ko[j]);
        if(nums.count(x) != 0) pairs++;
    }
    if(pairs % 2 == 0) printf("Karen\n");
    else printf("Koyomi\n");
    return 0;
}