#include <utility>
#include <cstdio>

using namespace std;

typedef pair<int,int> ii;

int Z, I, M, L;

int f(int x) {
    return (Z * x + I) % M;
}

ii floydCycleFinding(int x0) {
    int tortoise = f(x0), hare = f(f(x0));
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int mu = 0; hare = x0;
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    int lambda = 1; hare = f(tortoise);
    while(tortoise != hare) {
        hare = f(hare);
        lambda++;
    }
    return make_pair(mu, lambda);
}

int main(void) {
    int cases = 0;
    while(scanf("%d %d %d %d", &Z, &I, &M, &L)==4) {
        if(!(Z || I || M || L)) break;
        ii answ = floydCycleFinding(L);
        printf("Case %d: %d\n", ++cases, answ.second);
    }
    return 0;
}