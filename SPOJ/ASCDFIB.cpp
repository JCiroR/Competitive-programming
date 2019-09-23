//https://www.spoj.com/problems/ASCDFIB/


#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
const int T = 100, N = 1e5;

pii query[T];
int freq[T][N], t;

int main() {
    memset(freq, 0, sizeof(freq));
    scanf("%d", &t);
    int leastQ = 1e6 + 10, greatestQ = 0;
    for(int i = 0; i < t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        query[i] = pii(a, a + b);
        leastQ = min(leastQ, a);
        greatestQ = max(greatestQ, a + b);
    }
    int curr = 0, prev = 1, ith = 1;
    for(; ith <= greatestQ; ) {
        if(ith >= leastQ) {
            for(int j = 0; j < t; j++) {
                if(ith >= query[j].ff && ith <= query[j].ss)
                    freq[j][curr]++;
            }
        }
        int temp = curr;
        curr = (curr + prev) % N;
        prev = temp;
        ith++;
    }
    for(int i = 0; i < t; i++) {
        int rem = 100;
        bool space = false;
        printf("Case %d:", i + 1);
        for(int j = 0; j < N && rem > 0; j++) {
            while(freq[i][j] > 0 && rem > 0) {
                printf(" %d", j);
                rem--;
                freq[i][j]--;
            }
        }
        printf("\n");
    }
}