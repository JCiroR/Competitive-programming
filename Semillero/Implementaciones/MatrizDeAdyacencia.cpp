#include <iostream>
#include <algorithm>

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
    int AdjMat[MAXV][MAXV];
    //Inicializar el grafo en -1
    fill(&AdjMat[0][0], AdjMat[0][0] + sizeof(AdjMat), -1);
    //Añadir aristas
    int from, to, weight;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> weight;
        //Agregar arista from -> to con peso weight
        AdjMat[from][to] = weight;
        // Si es no dirigido, agregar arista to -> from
        AdjMat[to][from] = weight;
    }
    //Ejemplo: Recorrer hijos del nodo 1
    int node = 1;
    for(int i = 1; i <= V; i++) {
        //Si hay una arista
        if(AdjMat[node][i] != -1) process(i);
    }
}