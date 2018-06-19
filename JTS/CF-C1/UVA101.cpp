#include <iostream>
#include <cstring>

using namespace std;
const int MAXN = 26;
int height[MAXN], pos[MAXN], ans[MAXN], n;

int maxHOver(int stack)  {
    int h = 0;
    for(int i = 0 ; i < n; i++)
        if(pos[i] == stack) h = max(h, height[i]);
    return h;
}

void remove(int ind) {
    int h = height[ind], p = pos[ind];
    for(int i = 0; i < n; i++) {
        if(pos[i] == p && height[i] > h) {
            pos[i] = i;
            height[i] = 1;
        }
    }
}

void move(int a, int b) {
    int hFrom = height[a], hTo = maxHOver(pos[b]) + 1, posFrom = pos[a];
    for(int i = 0; i < n; i++)
        if(pos[i] == posFrom && height[i] >= hFrom) {
            pos[i] = pos[b];
            height[i] = height[i] - hFrom + hTo;
        }
}

void printAns() {
    for(int i = 0; i < n; i++) {
        cout << i << ':';
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(pos[j] == i) {
                ans[height[j]-1] = j;
                count++;
            }
        }
        for(int j = 0; j < count; j++)
           cout << ' ' << ans[j];
        cout << endl;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        height[i] = 1;
        pos[i] = i;
    }
    string op1, op2;
    while(cin >> op1 && (op1 != "quit")) {
        int a, b;
        cin >> a >> op2 >> b;
        if(a == b || pos[a] == pos[b]) continue;
        if(op1 == "move") {
            if(op2 == "onto") {
                remove(b);
                remove(a);
                pos[a] = pos[b];
                height[a] = height[b] + 1;
            } else {
                remove(a);
                pos[a] = pos[b];
                height[a] = maxHOver(pos[b]) + 1;
            }
        } else {
            if(op2 == "onto") remove(b);            
            move(a, b);
        }
    }
    printAns();
}