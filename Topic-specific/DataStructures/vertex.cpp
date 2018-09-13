#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

void dfs(vector<list<int> > &graph, int start) {
    int counter = 0;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    for(list<int>::iterator it = graph[start].begin(); it != graph[start].end(); ++it)
        q.push(*it);
    while(q.size() > 0) {
        int currNode = q.front();
        q.pop();
        if(!visited[currNode]) {
            visited[currNode] = true;
            for(list<int>::iterator it = graph[currNode].begin(); it != graph[currNode].end(); ++it)
                q.push(*it);
        }
    }    
    for(int i = 1; i < visited.size(); i++)
        if(!visited[i]) counter++;
    cout << counter;
    for(int i = 1; i < visited.size(); i++)
        if(!visited[i]) cout << " " << i;
    cout << "\n";
}

int main(void) {
    int size, from, to, queries, currQuery;

    while(cin >> size){
        if(size == 0) break;
        vector<list<int> > graph (size + 1, list<int>());
        while(cin >> from) {
            if(from == 0) break;
            while(cin >> to) {
                if(to == 0) break;
                graph[from].push_back(to);
            }
        }
        cin >> queries;
        while(queries--) {;
            cin >> currQuery;
            dfs(graph, currQuery);
        }
    }
    return 0;
}