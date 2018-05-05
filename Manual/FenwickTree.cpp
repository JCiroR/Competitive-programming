#include <vector>

using namespace std;

typedef vector<int> vi;

int LSOne(int b) {
    return (b & (-b));
}

class FenwickTree {
    private: vi ft;
    public: FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for(;b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1? 0 : rsq(a - 1));
    }
    void adjust(int k, int delta) {
        for(; k < ft.size(); k += LSOne(k)) ft[k] += delta;
    }
};

int main() {
    int f[] = {1,2,3,4};
    FenwickTree ft(4);
    for(int i = 0; i < 4; i++) {
        ft.adjust(f[i], 1);
    }
}