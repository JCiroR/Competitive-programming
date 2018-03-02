#include <vector>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

void canBeDecomposed(vector<list<int> > &graph) {
  vector<short> colored(graph.size(), 0);
  queue<int> q;
  bool canBeBicolored = true;
  q.push(1);
  colored[1] = 1;

  while(!q.empty()) {
      if(!canBeBicolored) break;
      int current = q.front();
      q.pop();
      for(list<int>::iterator it = graph[current].begin(); it != graph[current].end(); ++it) {
        if(colored[*it] == 0) {
          colored[*it] = colored[current] * -1;
          q.push(*it);
        } else if(colored[*it] == colored[current]) {
            canBeBicolored = false;
            break;
        }
      }
  }
  if(canBeBicolored) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main(void){
    int numNodes, numEdges, from, to;
    while(cin >> numNodes) {
        if(numNodes == 0) break;
        vector<list<int> > graph(numNodes + 1, list<int>());
        cin >> from >> to;
        while(from != 0 && to != 0) {
            graph[from].push_back(to);
            graph[to].push_back(from);
            cin >> from >> to;
        }
        canBeDecomposed(graph);
    }
    return 0;
}

