#include <iostream>

using namespace std;

bool hole[1000010];

int main() 
{
    int n, m, k, from, to;
    scanf("%d %d %d", &n, &m, &k);
    while(m--) {
        scanf("%d", &from);
        hole[from - 1] = true;
    }
    int pos = 0;
    while(k--) 
    {
        if(hole[pos]) break;
        scanf("%d %d", &from, &to);
        if(pos == from-1) pos = to-1;
        else if(pos == to-1) pos = from-1;
    }
    cout << pos + 1 << endl;
}