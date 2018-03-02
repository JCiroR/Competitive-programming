#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

int LSOne(int b) { return (b & (-b)); }

class FenwickTree {
    private: vi ft;
    public: 
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for(;b; b-= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1? 0: rsq(a-1));
    }
    void adjust(int k, int delta) {
        for(; k < ft.size(); k += LSOne(k)) ft[k] += delta;
    }
};

int main(void) {
    int T = 0, N;
    while(scanf("%d", &N)==1 && N) {
        if(T > 0) printf("\n");
        printf("Case %d:\n", ++T);
        FenwickTree ft(N+1);
        int pot;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &pot);
            ft.adjust(i, pot);
        }
        int x, y;
        string command;
        cin >> command;
        while(command != "END") {
            scanf("%d %d", &x , &y);
            if(command == "M") printf("%d\n", ft.rsq(x, y));
            else if (command == "S") {
                int before = ft.rsq(x,x);
                ft.adjust(x, y - before);
            }
            cin >> command;
        }
    }
    return 0;
}