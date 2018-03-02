#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

long long s[MAXN];
const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

const string f1a = "What are you doing while sending z";
const string f1b = "z? Are you busy? Will you send z";
const string f1c = "z?";

void fill_s() {
    s[0] = f0.size();
    for(int i = 1 ; i < MAXN; i++) {
        s[i] = min(f1a.size() + s[i-1] + f1b.size() + s[i-1] + f1c.size(),1000000000000000000);
    }
}

char machete(char x) { 
    if(x == 'z') return '"';
    else return x;
}

char query(int n, long long int k) {
    if(k > s[n]) return '.';
    if(n == 0) return machete(f0[k-1]);
    //f1a fn-1 f1b fn-1 f1c
    long long l1 = f1a.size();
    long long l2 = l1 + s[n - 1];
    long long l3 = l2 + f1b.size();
    long long l4 = l3 + s[n-1];
    long long l5 = l4 + f1c.size();

    if(k <= l1) return machete(f1a[k-1]);
    else if(k <= l2) return query(n - 1, k - l1);
    else if(k <= l3) return machete(f1b[k-l2 - 1]);
    else if(k <= l4) return query(n - 1, k - l3);
    else if(k <= l5) return machete(f1c[k - l4 - 1]);
    else return '.';
}

int main(void) {
    fill_s();
    int q, n;
    long long k;
    cin >> q;
    while(q--) {
        cin >> n >> k;
        cout << query(n, k);
    }
    cout << endl;
}