#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000
#define MAXN 200

int main(void) {
    int V, E, AdjMat[MAXN][MAXN];
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++)
            AdjMat[i][j] = INF;
        AdjMat[i][i] = 0;
    }
    //Fill matrix

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

    
}