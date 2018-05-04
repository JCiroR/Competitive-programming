#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<list<int> > &graph, vector<int> &orderedTasks, vector<bool> &visited, int i){
    visited[i] = true;
    for(list<int>::iterator it = graph[i].begin(); it != graph[i].end(); ++it)
        if(!visited[*it]) dfs(graph, orderedTasks, visited, *it);
    orderedTasks.push_back(i + 1);
}

vector<int> topologicalSort(vector<list<int> > &graph){
    vector<bool> visited (graph.size(), false);
    vector<int> orderedTasks;
    for(int i = 0; i < visited.size(); i++)if(!visited[i]) dfs(graph, orderedTasks, visited, i);
    reverse(orderedTasks.begin(), orderedTasks.end());
    return orderedTasks;
}

int main(void){
    int n, m, from, to;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<list<int> > graph (n, list<int>());
        while(m--){
            cin >> from >> to;
            graph[from-1].push_back(to-1);
        }

        vector<int> answer = topologicalSort(graph);
        cout << answer[0];
        for(int i = 1; i < answer.size(); i++)
          cout << " " << answer[i];
        cout << "\n";
    }
    return 0;
}