#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 10010;
int in[MAXN], pos[MAXN], tree[MAXN][2], size, leastLeaf, leastCost;
bool seen[MAXN*2];

int getRootIndex(int inFrom, int inTo, int root) {
    for(int i = inFrom; i <= inTo; i++)
        if(in[i] == root) return i;
    return -1;
}

void build(int posFrom, int posTo, int inFrom, int inTo, int parent, int index) {
    if(posFrom > posTo) return;
    tree[parent][index] = pos[posTo];
    if(posFrom == posTo) return;
    int rootIndex = getRootIndex(inFrom, inTo, pos[posTo]);

    if(rootIndex > inFrom) {
        build(posFrom, posFrom + (rootIndex - inFrom) - 1, inFrom, rootIndex - 1, pos[posTo], 0); 
    }
    if(rootIndex + 1 <= inTo) {
        build(posFrom + (rootIndex - inFrom) ,posTo - 1, rootIndex + 1, inTo, pos[posTo], 1); 
    }   
}

void dfs(int u, int cost) {
    seen[u] = true;
    if(tree[u][0] == 0 && tree[u][1] == 0 && u != 0) {
        if(cost < leastCost) {
            leastCost = cost;
            leastLeaf = u;
        } else if(cost == leastCost) leastLeaf = min(leastLeaf, u);
    }
    if(!seen[tree[u][0]] && tree[u][0] != 0) dfs(tree[u][0], cost + tree[u][0]);
    if(!seen[tree[u][1]] && tree[u][1] != 0) dfs(tree[u][1], cost + tree[u][1]);
}

int main(void) {
    string l1, l2;
    while(getline(cin, l1) && getline(cin, l2)) {
        stringstream s1, s2;
        s1 << l1; s2 << l2;
        int currIn, currPos;
        size = 0;
        while(s1 >> currIn && s2 >> currPos) {
            in[size] = currIn;
            pos[size] = currPos;
            size++;
         }
         memset(tree, 0, sizeof(tree));
         build(0, size-1, 0, size-1, 0, 0);
         leastCost = 100000000;
         memset(seen, false, sizeof(seen));
         dfs(0, 0);
         cout << leastLeaf << endl;
         l1.clear();
         l2.clear();
    }
    return 0;
}