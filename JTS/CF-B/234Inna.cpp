#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> distances;
    char temp;
    for(int i = 0; i < n; i++) 
    {
        int dwarf = -1, candy = -1;
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            if(temp == 'G') dwarf = j;
            else if(temp == 'S') candy = j;
        }
        if(candy < dwarf) { 
            cout << -1 << endl; 
            return 0; 
        }
        distances.insert(dwarf - candy);
    }
    cout << distances.size() << endl;
}