#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
bool panda[N];

int main() {
    memset(panda, false, sizeof(panda));
    queue<int> q;

    for(int i = 1; i <= 7; i++) {
        ll num = 1;
        for(int j = 0; j < i; j++)
            num *= i;
        if(num < N)
            q.push(num);
    }

    while(!q.empty()) {
        ll next = q.front();
        q.pop();
        if(next >= N || panda[next]) continue;
        else panda[next] = true;


        for(int i = 1; i <= 9; i++) {
            ll sum = i*i;
            sum += next;
            ll candidate = sum;
            bool can = false;
            while(candidate != 0) {
                int dig = candidate % 10;
                if(dig == i) can = true;
                candidate /= 10;
            }
            if(can) q.push(sum);
        }
    }

    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        if(panda[n]) printf("Yes\n");
        else printf("No\n");
    }
}