#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;
const int MAX = 110 * 110;
int id[MAX], size[MAX], nodes, edges;
pair<long long, pair<int,int> > p[MAX];
bool chosen[MAX];

void initialize() 
{
    for(int i = 0; i < MAX; ++i) 
    {
        id[i] = i;
        size[i] = i;
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

long long kruskal(pair<long long, pair<int, int> > p[], int exclude) 
{
    int x, y;
    long long cost, minimumCost = 0, comp = nodes;
    for(int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(i != exclude && root(x) != root(y))
        { 
            comp--;
            minimumCost += cost;
            union1(x, y);
            if(exclude == -1) chosen[i] = true;
        }
    }
    if(comp == 1) return minimumCost;
    else return INT_MAX;    
}

int main() {
    int T;
    cin >> T;
    while(T--) {    
        int x, y;
        long long weight, cost, minimumCost, secondMin;
        initialize();
        memset(chosen, false, sizeof(chosen));
        cin >> nodes >> edges;
        for(int i = 0; i < edges; ++i) 
        {
            cin >> x >> y >> weight;
            p[i] = make_pair(weight, make_pair(x, y));
        }
        sort(p, p + edges);
        minimumCost = kruskal(p, -1);
        secondMin = INT_MAX;
        for(int i = 0; i < edges; ++i)
            if(chosen[i]) {
                initialize();
                secondMin = min(secondMin, kruskal(p, i));
            }
        cout << minimumCost << " " << secondMin << endl;
    }
}