#include <cstdio>
#include <algorithm>
#include <utility>

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


void build(int node, int a, int b) {
    if(a > b) return; // Out of range
	if(a == b) { // Leaf node
		 // Init value
        treeF[node] = leftF[node] = rightF[node] = 1;
        leftMost[node] = rightMost[node] = tree[node]  = A[a];
		return;
	}

	build(node*2, a, (a+b)/2); // Init left child
	build(node*2+1, 1+(a+b)/2, b); // Init right child
    //printf("%i,%i : %i,%i - %i,%i\n", a,b,a,(a+b)/2, 1 +(a+b)/2, b);
    rightMost[node] = rightMost[node*2+1];
    leftMost[node] = leftMost[node*2];
    rightF[node] = rightF[node*2+1];
    leftF[node] = leftF[node*2];
    if(rightMost[node*2] != leftMost[node*2+1]) { //xxa byy
        if(treeF[node*2] > treeF[node*2+1]) {
            treeF[node] = treeF[node*2];
            tree[node] = tree[node*2];
        }  else {
            treeF[node] = treeF[node*2+1];
            tree[node] = tree[node*2+1];
        }
    } else { //xxa ayy
        int thirdCandidate = rightMost[node*2], thirdCandidateF = rightF[node*2] + leftF[node*2+1];
        if(thirdCandidateF > treeF[node*2] && thirdCandidateF > treeF[node*2+1]) {
            tree[node] = thirdCandidate;
            treeF[node] = thirdCandidateF;
        } else {
            if(treeF[node*2] > treeF[node*2+1]) {
                treeF[node] = treeF[node*2];
                tree[node] = tree[node*2];
            }  else {
                treeF[node] = treeF[node*2+1];
                tree[node] = tree[node*2+1];
            }
        }
        if(rightMost[node*2+1] == rightMost[node*2]) rightF[node] = thirdCandidateF; // xxa aaa
        if(leftMost[node*2] == leftMost[node*2+1]) leftF[node] = thirdCandidateF;    //aaa axx
    }
}

pair<int,int> query(int p, int L, int R, int i, int j) {
    if(i > R || j < L) return make_pair(-1,0);
    if(L >= i && R <= j) return make_pair(treeF[p], tree[p]); //inside query range

    pair<int,int> p1 = query(p<<1, L , (L+R)/2, i, j);
    pair<int,int> p2 = query(p<<1|1, (L+R)/2 +1, R,i ,j);

    if(p1.first == -1) return p2;
    if(p2.first == -1) return p1;
    if(p1.second == p2.second) return make_pair(p1.first + p2.first, p1.second);
    else return (p1.first > p2.first)? p1:p2;
}

int queery(int p, int L, int R, int i, int j) {
    pair<int,int> answ = query(p,L,R,i,j);
    return answ.first;
}


int main(void) {
    int n, q;
    scanf("%i", &n);
    while(n != 0) {
        scanf("%i", &q);
        clear(n);
        for(int i = 0; i < n; i++)
            scanf("%i", &A[i]);
        build(1, 0, n-1);
        int l, r;
        while(q--){
            scanf("%i %i", &l, &r);
            l--; r--;
            int answ = queery(1, 0, n-1, l, r);
            printf("%i\n", answ);
        }
        scanf("%i",&n);
    }

    return 0;
}