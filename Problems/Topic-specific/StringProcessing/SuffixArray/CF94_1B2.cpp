#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 20;
char s[N];
typedef long long ll;
ll n;

struct subs {
    int start;
    int size;

    bool operator < (const subs &second) const 
    {
        int len = min(size, second.size);
        int test = strncmp(&s[start], &s[second.start], len);
        if(test < 0) return false;
        else if(test > 0) return true;
        else return size > second.size;
    }
};

int main() {
    scanf("%s\n", &s[0]);
    n = strlen(&s[0]);
    ll lim = n * (n + 1LL);
    lim /= 2;
    
    int k;
    scanf("%d", &k);
    if(k > lim) {
        printf("No such line.\n");
        return 0;
    }
    priority_queue<subs> pq;
    for(int i = 0; i < n; i++) {
        subs curr;
        curr.start = i;
        curr.size = 1;
        pq.push(curr);
    }

    
    while(k--) {
        subs top = pq.top();
        // cout << "(" <<  top.start << " " << top.size << ")" << endl;
        pq.pop();
        if(k == 0)
            printf("%.*s\n", top.size, &s[top.start]);
        if(top.size < n - top.start) {
            top.size++;
            pq.push(top);
        }
        
    }
}