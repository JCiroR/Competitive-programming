//Wrong, so complex to debugg, I rather make a new one

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

int A[MAXN];
int tree[2*MAXN];
int treeF[2*MAXN];

int leftMost[2*MAXN];
int rightMost[2*MAXN];
int leftF[2*MAXN];
int rightF[2*MAXN];

void clear(int n) {
    fill(A, A+n, 0);
    fill(tree, tree + (n*2 + 1), 0);
    fill(treeF, treeF + (n*2 + 1), 0);
    fill(leftMost, leftMost + (n*2 + 1), 0);
    fill(rightMost, rightMost + (n*2 + 1),0);
    fill(leftF, leftF + (n*2 + 1), 0);
    fill(rightF, rightF + (n*2 + 1),0);
}   


void build() {

}

void build(int n) {
    for(int i = n - 1; i > 0; i--) {
        leftMost[i] = leftMost[i << 1];
        rightMost[i] = rightMost[i << 1|1];
        if(rightMost[i << 1] != leftMost[i << 1|1]) { //Just take the one with greater frequency
            leftF[i] = leftF[i << 1];
            rightF[i] = rightF[i << 1|1];
            if(treeF[i << 1] > treeF[i << 1|1]) {
                tree[i] = tree[i << 1];
                treeF[i] = treeF[i << 1];
            } else {
                tree[i] = tree[i << 1|1];
                treeF[i] = treeF[i << 1|1];
            }
        } else {
            if(rightMost[i<<1] != tree[i<<1] && rightMost[i<<1] != tree[i<<1|1]) {
                int candidateF = rightF[i<<1] + leftF[i<<1|1];
                leftF[i] = leftF[i<<1];
                rightF[i] = rightF[i<<1|1];
                if(candidateF > treeF[i<<1] && candidateF > treeF[i<<1|1]) { 
                    //Take the central number
                    tree[i] = rightMost[i<<1];
                    treeF[i] = candidateF;
                } else if(treeF[i << 1] > treeF[i << 1|1]){
                    tree[i] = tree[i << 1];
                    treeF[i] = treeF[i << 1];
                } else {
                    tree[i] = tree[i << 1|1];
                    treeF[i] = treeF[i << 1|1];
                }
            } else if(rightMost[i<<1] == tree[i<<1] && rightMost[i<<1] == tree[i<<1|1]) {
                tree[i] = rightMost[i<<1];
                treeF[i] = treeF[i<<1] + treeF[i<<1|1];
                if(rightMost[i] == tree[i]) {
                    rightF[i] = treeF[i];
                } else rightF[i] = rightF[i<<1|1];
                if(leftMost[i] == tree[i]) {
                    leftF[i] = treeF[i];
                } else leftF[i] = leftF[i<<1];
            } else if (rightMost[i<<1] == tree[i<<1|1]) {
                leftF[i] = leftF[i<<1];
                int rightCandidateF = treeF[i<<1|1] + rightF[i<<1];
                if(rightMost[i<<1|1] == tree[i<<1|1]) rightF[i] = rightCandidateF;
                else rightF[i] = rightF[i<<1|1];
                if(rightCandidateF > treeF[i<<1]) {
                    tree[i] = tree[i<<1|1];
                    treeF[i] = rightCandidateF;
                } else {
                    tree[i] = tree[i<<1];
                    treeF[i] = treeF[i<<1];
                }
            } else {
                rightF[i] = rightF[i<<1|1];
                int leftCandidateF = treeF[i<<1] + leftF[i<<1|1];
                if(leftMost[i<<1] == treeF[i<<1]) leftF[i] = leftCandidateF;
                else leftF[i] = leftF[i<<1];
                if(leftCandidateF > treeF[i<<1|1]) {
                    tree[i] = tree[i<<1];
                    treeF[i] = leftCandidateF;
                } else {
                    tree[i] = tree[i<<1|1];
                    treeF[i] = treeF[i<<1|1];
                }
            }
        }
    }
}

int query(int p, int L, int R, int i, int j) {
    if(i > R || j < L) return -1;
    if(L >= i && R <= j) return treeF[p]; //inside query range

    int p1 = query(p<<1, L , (L+R)/2, i, j);
    int p2 = query(p<<1|1, (L+R)/2 +1, R,i ,j);

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return (p1 > p2)? p1:p2;
}

int main(void) {
    int n, q;
    scanf("%i", &n);
    while(n != 0) {
        scanf("%i", &q);
        clear(n);
        for(int i = 0; i < n; i++) {
            scanf("%i", &A[i]);
            tree[n + i] = leftMost[n + i] = rightMost[n + i] = A[i];
            treeF[n + i] = rightF[n + i] = leftF[n + i] = 1;

        }
        build(n);
        int l, r;
        while(q--){
            scanf("%i %i", &l, &r);
            l--; r--;
            int answ = query(1, 0, n-1, l, r);
            printf("%i\n", answ);
        }
        scanf("%i",&n);
    }

    return 0;
}