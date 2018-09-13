#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

int LSOne(int b) {
    return (b & (-b));
}

class FenwickTree {
    private: vi ft;
    public: FenwickTree(int n) {
        ft.assign(n + 1 , 0);
    }
    int rsq(int b) {
        int sum = 0;
        for(;b;b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1? 0 : rsq(a-1));
    }
    void adjust(int k, int delta) {
        for(; k < ft.size(); k += LSOne(k)) ft[k] += delta;
    }
};

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
        FenwickTree zero(n);
        FenwickTree neg(n);
        int xi;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &xi);
            if(xi == 0) zero.adjust(i, 1);
            else if(xi < 0) neg.adjust(i, 1);
        }
        scanf("\n");
        char com;
        int x, y;
        while(k--) {
            scanf("%c %d %d\n", &com, &x, &y);
            //printf("%c %d %d\n", com, x, y);
            int zeroes, negs;
            if(com == 'C') {
                zeroes = zero.rsq(x,x);
                negs = neg.rsq(x,x);
                if(y  == 0 && zeroes == 0) zero.adjust(x, 1);
                if(y < 0 && negs == 0) neg.adjust(x, 1);
                else if(y > 0) {
                    if(zeroes != 0) zero.adjust(x, -1*zeroes);
                    if(negs != 0) neg.adjust(x, -1*negs);
                }
            } else if(com == 'P') {
                zeroes = zero.rsq(x, y);
                negs = neg.rsq(x, y);
                if(zeroes > 0) printf("0");
                else if(negs & 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
}