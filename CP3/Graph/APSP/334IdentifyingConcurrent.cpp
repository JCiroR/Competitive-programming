#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

const int MAXN = 210;
short AdjMat[MAXN][MAXN];
string names[MAXN];

void floyd(int V) {
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
}

int main(void) {
    int T = 0, V;
    while(cin >> V && (V)) {
        int size = 0;
        map<string, int> index;
        int events;
        for(int i = 0; i < MAXN; i++)
            for(int j = 0; j < MAXN; j++)
                AdjMat[i][j] = 0;

        for(int i = 0; i < V; i++) {
            cin >> events;
            string event;
            for(int j = 0; j < events; j++) {
                cin >> event;
                index[event] = size;
                names[size] = event;
                if(j > 0) AdjMat[size-1][size] = 1;
                size++;
            }            
        }
        int messages;
        cin >> messages;
        string from, to;
        while(messages--) {
            cin >> from >> to;
            AdjMat[index[from]][index[to]] = 1;
        }
        floyd(size);
        
        int cPairs = 0;
        pair<string,string> p1, p2;
        for(int i = 0; i < size; i++)
            for(int j = i; j < size; j++) {
                if(i == j) continue;
                if(!AdjMat[i][j] && !AdjMat[j][i]) {
                    cPairs++;
                    if(cPairs == 1) p1 = make_pair(names[i], names[j]);
                    if(cPairs == 2) p2 = make_pair(names[i], names[j]);
                }
            }


        if(cPairs == 0) printf("Case %d, no concurrent events.\n", ++T);
        else {
            printf("Case %d, %d concurrent events:\n", ++T, cPairs);
            cout << '(' << p1.first << ',' << p1.second << ") ";
            if(cPairs > 1) cout << '(' << p2.first << ',' << p2.second << ") ";
            cout << endl;
        }
    }
    return 0;
}