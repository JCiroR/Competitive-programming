#include <bitset>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 20000010;

ll _sieve_size;
bitset<MAXN> bs;
int nextP;
pair<int,int> ans[100010];

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++)
        if(bs[i]) {
            if(bs[i-2] && nextP <= 100005)
                ans[nextP++] = make_pair(i-2, i);            
            for(ll j = i*i; j <= _sieve_size; j+= i)
                bs[j] = 0;            
        }
}

int main() {
    nextP = 0;
    sieve(20000005);
    int x;
    while(scanf("%d", &x) == 1) {
        x--;
        printf("(%d, %d)\n", ans[x].first, ans[x].second);
    }
}