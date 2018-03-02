#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Número máximo de vertices que el problema puede requerir
//+1 Para indexar desde uno
const int MAXV = 100 + 1;

void process(int node) {
    cout << node << endl;
}

int main() {
    //Numero de vertices y aristas que el problema requiere
    int V, E; 
    cin >> V >> E;
    //Parejas (DistanciaRequerida, nodoAlQueVoy)
    vector<pair<int,int> > AdjList[MAXV];
    
    //Inicializar el grafo (Que ningun vertice tenga aristas)
    for(int i = 0; i < MAXV; i++)
        AdjList[i].clear();
            
    //Añadir aristas
    int from, to, weight;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;    
        //Crear y agregar arista from -> to con peso weight
        //En la lista de hijos del nodo from
        AdjList[from].push_back(make_pair(weight, to));
        // Si es no dirigido, agregar arista to -> from
        AdjList[to].push_back(make_pair(weight, from));
    }

    //Ejemplo: Imprimir los hijos de todos los nodos
    //Indexando desde 1
    for(int node = 1; node <= V; node++) {
        cout << node << ": ";
        //Todos los elementos en la lista de hijos
        for(int i = 0; i < AdjList[node].size(); i++) {
            pair<int,int> child = AdjList[node][i];
            cout << child.second << " ";
        }
        cout << endl;
    }               
}