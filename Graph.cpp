#include <vector>
#include <iostream>
#include <list>

using namespace std;

vector<list<int> > graph;

void initializeGraph(int size){
    for(int i = 0; i < size; i++) {
        list<int> currentList;
        graph.push_back(currentList);
    }
}
void dfs(vector<list<int> > ggraph) {
    bool[vector.]visited;
}

void dfsAux(vector<list<int> > ggraph, ) {
    

}

int main(void){
    int size, rep;
    cin >> size >> rep;
    initializeGraph(size);
    int from,to;
    for(int i = 0; i < rep; i++){
        cin >> from >> to;
        graph[from].push_front(to);
    }
    //graph[0].push_front(1);
    return 0;
}


//////////////////////// Otra opción

int main(void){
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<list<short> > graph(numNodes, list<short>());
    graph[0].push_back(0);
    graph[2].push_back(23);

    for(int i = 0; i < numNodes; i++) {
            cout << "Elemento posicion vector " << i << " valor " << graph[i].front() << endl;
    }
    return 0;
}