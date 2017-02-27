#include <vector>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

void canBeBicolored(vector<list<int> > &graph) {
  vector<short> colored(graph.size(), 0);     //Default value is 0
  queue<int> q;
  bool canBeBicolored = true;
  q.push(0);
  colored[0] = 1;

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
  if(canBeBicolored) cout << "BICOLORABLE." << endl;
  else cout << "NOT BICOLORABLE." << endl;
}

int main(void){
    int numNodes, numEdges, from, to;
    
    while(cin >> numNodes) {
      if(numNodes == 0) break;
      cin >> numEdges;
      
      vector<list<int> > graph(numNodes, list<int>());

       for(int i = 0; i < numEdges; i++) {
         cin >> from >> to;;
         graph[from].push_back(to);
         graph[to].push_back(from);
       }
       canBeBicolored(graph);
    }
    return 0;
}