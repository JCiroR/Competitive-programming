#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 1000*1000;
int id[MAX], size[MAX], nodes, edges;
pair<float, pair <int, int> > p[MAX];
pair<int, int> g[760];
bool used = false;

void initialize()
{
    for(int i = 0 ; i < MAX; ++i)
    {
        id[i] = i;
        size[i] = 1;
    }
}

int root(int x)
{
    while(id[x] != x) 
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(size[p] < size[q])
    {
        id[p] = id[q];
        size[q] += size[p];
    } else {
        id[q] = id[p];
        size[p] += size[q];
    }
}

float kruskal(pair<float, pair<int, int> > p[]) 
{
    int x, y;
    float cost, minimumCost = 0;
    for(int i = 0; i < edges; ++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        //cout << x << " - " << y << endl;
        //cout << root(x) << " " << root(y) << endl;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            used = true;
            minimumCost += cost;
            union1(x, y);
            cout << x + 1<< " " << y + 1<< endl;
        }        
    }
    return minimumCost;
}

float dis(int i, int j) {
    float x1 = g[i].first, y1 = g[i].second;
    float x2 = g[j].first, y2 = g[j].second;
    return hypot(x1 - x2, y1 - y2);
}

int main() {
    int T;
    cin >> T;
    while(T--) {    
        int x, y;    
        initialize();
        cin >> nodes;
        for(int i = 0; i < nodes; i++) {
            cin >> x >> y;
            g[i] = make_pair(x, y);
        }
        cin >> edges;
        for(int i = 0; i < edges; ++i)
        {
            cin >> x >> y;
            union1(x - 1, y -1);    
        }
        edges = 0;
        for(int i = 0; i < nodes; i++)
            for(int j = i + 1; j < nodes; j++) {
                p[edges] = make_pair(dis(i,j),make_pair(i, j));            
                edges++;
            }
        sort(p, p + edges);
        used = false;        
        kruskal(p);
        if(!used) cout << "No new highways need" << endl;
        if(T) cout << endl;
    }
}