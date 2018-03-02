#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 200;

char tree[MAXN];

void postOrder(int i) {
    if(tree[i*2] != '1') postOrder(i*2);
    if(tree[i*2 + 1] != '1') postOrder(i*2 + 1);
    printf("%c", tree[i]);
}

void build(string pre, string in, int index) {
    if(pre.empty()) return;
    tree[index] = pre[0];
    if(pre.size() > 1) {
        string leftP = pre.substr(1, in.find(pre[0]));
        string leftIn = in.substr(0, in.find(pre[0]));
        build(leftP, leftIn, index*2);
    }
    if(pre.size() > in.find(pre[0]) + 1) {
        string rightP = pre.substr(in.find(pre[0]) + 1);
        string rightIn = in.substr(in.find(pre[0]) + 1);
        build(rightP, rightIn, index*2 + 1);
    }   
}


int main(void) {
    string pre, in;
    while(cin >> pre >> in) {
        memset(tree, '1', sizeof(tree));
        build(pre, in, 1);    
        postOrder(1);
        printf("\n");
    }
}