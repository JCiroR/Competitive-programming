#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1001;
vector<int> graph[MAXN];
set<int> result[MAXN];
bool seen[MAXN];
bool imIn[MAXN];
short conv[MAXN];

bool dfsC(int n) {
    if(imIn[n]) return false;
    imIn[n] = true;
    
    for(int i = 0; i < graph[n].size(); i++)
        if(!dfsC(graph[n][i])) return false;
    
    imIn[n] = false;
    return true;
}

bool noCicle(int n) {
    //clear
    for(int i = 0; i < n; i++) seen[i] = imIn[i] = false;
    for(int i = 0; i < n; i++) 
        if(!seen[i]) {
            seen[i] = true;
            if(!dfsC(i)) return false; 
        }
    return true;
}

set<int> intersect(set<int> &a, set<int> &b) {
    set<int> answ;
    for(set<int>::iterator it = a.begin(); it != a.end(); ++it) {
        if(b.count(*it) != 0) answ.insert(*it);
    }
    return answ;
}
 
set<int> dfsB(int n) {
    if(result[n].size() != 0) return result[n];
    // else
    set<int> answ;
    if(graph[n].size() == 0) {
            answ.insert(n);
    } else {
        for(int i = 0; i < graph[n].size(); i++) {
            set<int> son = dfsB(graph[n][i]);
            answ.insert(son.begin(), son.end());
        }
    }
    result[n] = answ;
    return answ;
}

bool converges(int n) {
    if(graph[n].size() == 0) return true;
    set<int> intersection = dfsB(graph[n][0]);
    for(int i = graph[n].size() - 1; i > 0; i--) {
        if(conv[ graph[n][i] ] == -1) {
            conv[n] = -1;
            return false;
        }
        intersection = intersect(intersection, result[ graph[n][i]]);
        if(intersection.size() == 0) { 
            conv[n] = -1;
            return false;
        }
    }
    conv[n] = 1;
    return true;
}

bool graphConverges(int n) {
    for(int i = 0; i < n; i++) {
        result[i].clear();
        conv[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        result[i] = dfsB(i);
    }
    for(int i = 0; i < n; i++) {
        if(conv[i] == 0) { if (!converges(i)) return false;}
        else if(conv[i] == -1) return false;
    }
    return true;
}


    
void clear(int n) {
    for(int i = 0; i < n; i++) {
        graph[i].clear();
    }
}

int main(void){
    int n, m, from, to;
    while(scanf("%i %i", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        clear(n);
        for(int i = 0; i < m; i++) {
            scanf("%i %i", &from, &to);
            graph[from].push_back(to);
        }   
        if(noCicle(n) && graphConverges(n)) printf("1\n");
        else printf("0\n");
    }
} 