#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;
const int MAXN = 105;
vector<int> graph[MAXN];
bool nodominator[MAXN][MAXN];
bool reachable[MAXN];
bool seen[MAXN];

void dfs(int u, int pdom) {
        for(int i = 0; i < graph[u].size(); i++) {
            int vert = graph[u][i];
            if(!seen[vert]) {
                seen[vert] = true;
                nodominator[pdom][vert] = true;
                dfs(vert, pdom);
            }
        }
}

void dfs(int u) {
    seen[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
        int vert = graph[u][i];
        if(!seen[vert]) {
            reachable[vert] = true;
            dfs(vert);
        }
    }
}

void tryDominator(int n) {
    dfs(0);
    reachable[0] = true;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) seen[j] = false;
        seen[i] = true;
        seen[0] = true;
        nodominator[i][0] = true;
        dfs(0, i);
    }
}

void cleanTil(int n) {
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n; j++) {
            nodominator[i][j] = false;
        }
        reachable[i] = false;
        graph[i].clear();
        seen[i] = false;
    } 
}

int main(void) {
    int test, n, currTest = 1, to;
    cin >> test;
    while(test--) {
        cin >> n;
        cleanTil(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> to;
                if(to == 1) graph[i].push_back(j);
            }
        }
        string separator(2 * n - 1, '-');
        separator = "+" + separator;
        separator += '+';
        cout << "Case "<< currTest++ << ":\n" << separator << "\n";
        tryDominator(n);
        
        char dom;        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(reachable[j] && reachable[i]) {
                    dom = (nodominator[i][j])? 'N':'Y';
                } else dom = 'N';
                cout << '|' << dom;
            }
            cout << "|\n" << separator << "\n";
        }
    }
    return 0;
}
