#include <bits/stdc++.h>
using namespace std;

struct node {
    char id;
    int c1;
    int c2;
};

vector<node> h;
int T, n, p, e1, e2;
string s;

int expression() {
    node a;
    a.id = s[p++];
    if(a.id != '0') {
        p++;
        a.c1 = expression();
        p++;
        if(a.id != 'i') {
            a.c2 = expression();
            p++;
        }
    }
    h.push_back(a);
    return h.size() - 1;
}

void rule1(int u) {
    while(h[u].id == 'i')
        h[u] = h[h[u].c1];
    node a = h[u];
    if(a.id != '0') {
        rule1(a.c1);
        if(a.id != 'i') rule1(a.c2);
    }   
}

void rule2(int u) {
    while(h[u].id == 't' && h[h[u].c2].id == 't' && h[h[h[u].c2].c2].id == '0') {
        int temp = h[u].c1;
        h[u].id = 'k';
        h[u].c1 = h[h[u].c2].c1;
        h[u].c2 = temp;
    }
    node a = h[u];
    if(a.id != '0') {
        rule2(a.c1);
        if(a.id != 'i') rule2(a.c2);
    }
}

bool equal(int a, int b) {
    if(h[a].id != h[b].id) return false;
    else if(h[a].id == '0') return true;
    else if(h[a].id == 'i') return equal(h[a].c1, h[b].c1);
    else return  equal(h[a].c1, h[b].c1) &&  equal(h[a].c2, h[b].c2);
}

int main () {
    h.reserve(100);
    cin >> T;
    while(T--) {
        h.clear();
        for(int i = 0; i < 2; i++) {
            cin >> s;
            n = s.size();
            p = 0;
            if(i == 0) e1 = expression();
            else e2 = expression();
        }
        rule1(e1); rule2(e1);
        rule1(e2); rule2(e2);
        if(equal(e1, e2)) cout << "true\n";
        else cout << "false\n";
    }
}