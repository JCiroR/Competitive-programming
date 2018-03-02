#include <sstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXV = 105;
const int INF = 100000;

int Old[MAXV][MAXV];
int New[MAXV][MAXV];

void floyd(int V) {
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++) {
                Old[i][j] = min(Old[i][j], Old[i][k] + Old[k][j]);
                New[i][j] = min(New[i][j], New[i][k] + New[k][j]);
            }
}

bool comp(int A, int B, int V) {
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++) {
            if(i == j) continue;
            if(New[i][j] > Old[i][j] * A + B) return false;
        }
    return true;
}   

int main(void) {
    int V;
    string trash;
    while(cin >> V && (V)) {
        getline(cin, trash);
        for(int i = 0; i < V; i++) 
            for(int j = 0; j < V; j++) 
                Old[i][j] = New[i][j] = INF;
        int from, to; 
        for(int i = 0; i < V; i++) {
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            ss >> from; from--;
            while(ss >> to) {
                to--;
                Old[from][to] = 1;
            }
        }
        for(int i = 0; i < V; i++) {
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;
            ss >> from; from--;
            while(ss >> to) {
                to--;
                New[from][to] = 1;
            }
        }
        int A, B;
        cin >> A >> B;   
        floyd(V);
        if(comp(A,B,V)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}