#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000
#define MAXV 22

double AdjMat[MAXV][MAXV][MAXV];
int p[MAXV][MAXV][MAXV];

void printAns(int i, int j, int s) {
    if(s > -1) {
        printAns(i, p[i][j][s], s - 1);
        printf(" %d", j + 1);
    }
}

void floyd(int V) {
    for(int s = 1; s < V; s++)
        for(int k = 0; k < V; k++)
            for(int i = 0; i < V; i++)
                for(int j = 0; j < V; j++) {
                    double temp = AdjMat[i][k][s - 1] * AdjMat[k][j][0];
                    if(temp > AdjMat[i][j][s]) {
                        AdjMat[i][j][s] = temp;
                        p[i][j][s] = p[k][j][0];
                    }
                }
 }

int main(void) {
    int V;
    while(scanf("%d", &V) == 1) {
       for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                for(int s = 1; s < V; s++)
                    AdjMat[i][j][s] = -1;


        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                p[i][j][0] = i;
                if(j == i) {
                    AdjMat[i][i][0] = 1.0;
                    continue;                
                }
                scanf("%lf", &AdjMat[i][j][0]);        
            }
        }
        floyd(V);
        bool found = false;
        for(int s = 0; s < V && !found; s++) {
            for(int i = 0; i < V && !found; i++) {
                if(AdjMat[i][i][s] > 1.01) {
                    found = true;
                    printf("%d", i + 1);
                    printAns(i,i, s);
                    printf("\n");
                }
            }
        }
        if(!found) printf("no arbitrage sequence exists\n");
    }
}