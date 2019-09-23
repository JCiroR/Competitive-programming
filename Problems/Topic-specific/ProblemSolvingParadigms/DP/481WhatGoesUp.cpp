//LIS in O(n log k).
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 100000;
int L[MAXN];
int P[MAXN];
int L_id[MAXN];
int A[MAXN];

void printFrom(int end) {
    stack<int> seq;
    while(end >= 0) {
        seq.push(A[end]);
        end = P[end];
    } 
    while(!seq.empty()) {
        printf("%i\n", seq.top());
        seq.pop();
    }
}

int main(void) {
    int i = 0;
    int lis = 0, lis_end = 0;

    while(scanf("%i", &A[i]) != EOF) {
        int pos = lower_bound(L, L + lis, A[i]) - L;
        L[pos] = A[i];
        L_id[pos] = i;
        P[i] = (pos)? L_id[pos-1]: -1;

        if(pos + 1 > lis) {
            lis++;
            lis_end = i;
        } else if(pos + 1 == lis) lis_end = i;
        i++;
    }
    printf("%i\n-\n", lis); 
    printFrom(lis_end);
}