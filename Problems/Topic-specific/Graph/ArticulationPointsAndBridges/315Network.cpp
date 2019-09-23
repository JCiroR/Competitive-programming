#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 105;
vector<int> g[MAXN];
int low[MAXN], num[MAXN], parent[MAXN];
bool visited[MAXN], AP[MAXN];
int iteration = 0;


void clear(int n) {
    for(int i = 0; i <= n; i++) g[i].clear();
    memset(low, -1,sizeof(low));
    memset(num, -1, sizeof(low));
    memset(parent, -1, sizeof(parent));
    memset(visited, false, sizeof(visited));
    memset(AP, false, sizeof(AP));
}

void findAP(int u) {
    int children = 0; 
    num[u] = low[u] = iteration++;
    visited[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        int child = g[u][i];
        if(!visited[child]) {

            children++;
            parent[child] = u;
            findAP(child);
            low[u] = min(low[u], low[child]);
            if(parent[u] == -1 && children > 1) AP[u] = true; 
            if(parent[u] != -1 && low[child] >= num[u]) AP[u] = true;
        } else if(parent[u] != child) low[u] = min(low[u], num[child]);
    }
}

int main(void) {
    int n; string tempN;
    while(cin >> n && (n)) {
        clear(n);
        getline(cin,tempN);
        int from; int to;
        while(true) {
            stringstream ss; string line;
            getline(cin, line);
            ss << line;
            ss >> from;
            if(from == 0) break;
            else while(ss >> to) {
                g[from - 1].push_back(to - 1);
                g[to - 1].push_back(from - 1);
            }
        }
        iteration = 0;
        findAP(0);
        int count = 0;
        for(int i = 0; i < n; i++) if(AP[i])count++;
        cout << count << endl;   
    }   
}